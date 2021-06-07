import json
import networkx as nx
import copy as cp


class RouteGenerator(nx.Graph):

    def __init__(self):
        nx.Graph.__init__(self)

    # Yen's algorithm for k shortest paths
    def k_shortest_paths(self, source, target, k=1):
        # Determine the shortest path from the source to the sink.
        path_list = [nx.dijkstra_path(self, source, target, weight='weight')]
        # Initialize the set to store the potential kth shortest path.
        path_length_list = [sum([self[path_list[0][i]][path_list[0][i + 1]]['weight']
                                 for i in range(len(path_list[0]) - 1)])]
        # Set to store the distances of the paths
        time_sum = 0
        for i in range((len(path_list[0]) - 1) // 2):
            time_sum += max(self[path_list[0][i]][path_list[0][i + 1]]['weight'],
                            self[path_list[0][len(path_list[0]) - i - 1]]
                            [path_list[0][len(path_list[0]) - i - 2]]['weight'])
        if (len(path_list[0]) - 1) % 2 == 1:
            time_sum += \
                self[path_list[0][(len(path_list[0]) - 1) % 2]][path_list[0][(len(path_list[0]) - 1) % 2 + 1]]['weight'] / 2

        path_time_list = [time_sum]  # set to store the times of the paths

        path_list_buffer = []

        for iterator in range(1, k):
            # The spur node ranges from the first node to the next to last node in the previous k-shortest path.
            for j in range(0, len(path_list[-1]) - 1):
                graph_copy = cp.deepcopy(self)
                # Spur node is retrieved from the previous k-shortest path, k − 1.
                spur_node = path_list[-1][j]
                # The sequence of nodes from the source to the spur node of the previous k-shortest path.
                root_path = path_list[-1][:j + 1]
                for path in path_list:
                    if root_path == path[0:j + 1]:  # and len(path) > j?
                        if graph_copy.has_edge(path[j], path[j + 1]):
                            # Remove the links that are part of the previous shortest paths
                            # which share the same root path.
                            graph_copy.remove_edge(path[j], path[j + 1])
                        if graph_copy.has_edge(path[j + 1], path[j]):
                            graph_copy.remove_edge(path[j + 1], path[j])
                for n in root_path:
                    if n != spur_node:
                        graph_copy.remove_node(n)
                try:
                    # Calculate the spur path from the spur node to the sink.
                    # Consider also checking if any spurPath found
                    spur_path = nx.dijkstra_path(graph_copy, spur_node, target, weight='weight')
                    # Entire path is made up of the root path and spur path
                    total_path = root_path + spur_path[1:]
                    # Add the potential k-shortest path to the heap.
                    if total_path not in path_list_buffer:
                        path_list_buffer += [total_path]
                except nx.NetworkXNoPath:
                    continue
            if len(path_list_buffer) == 0:
                break

            # getting the length of every path in the buffer
            path_length_buffer = [sum([self[path[i]][path[i + 1]]['weight']
                                       for i in range(len(path) - 1)]) for path in path_list_buffer]
            # Sort the potential k-shortest paths by cost.
            path_list_buffer = [p for _, p in sorted(zip(path_length_buffer, path_list_buffer))]

            # Getting the time of every path in the buffer
            for path in path_list_buffer:
                time_sum = 0
                for i in range((len(path) - 1) // 2):
                    time_sum += max(self[path[i]][path[i + 1]]['weight'],
                                    self[path[len(path) - i - 1]][path[len(path) - i - 2]]['weight'])
                if (len(path) - 1) % 2 == 1:
                    time_sum += self[path[(len(path) - 1) % 2]][path[(len(path) - 1) % 2 + 1]]['weight'] / 2
                path_time_list.append(time_sum)

            # Add the lowest cost path becomes the k-shortest path.
            path_list.append(path_list_buffer[0])
            path_length_list.append(sorted(path_length_buffer)[0])
            path_list_buffer.remove(path_list_buffer[0])

        return path_list, path_length_list, path_time_list

    def load_data(self, json_file, data_set):
        # opening the file and loading its data node by node
        with open(json_file) as file:
            sample = json.load(file)
            for edge in sample[data_set]:
                self.add_edge(
                    sample[data_set][edge]['source'],
                    sample[data_set][edge]['target'],
                    weight=int(sample[data_set][edge]['weight'])
                )

    def optimal_route(self, source, target, k=3):
        path_list, path_length_list, path_time_list = self.k_shortest_paths(source, target, k)
        time = path_time_list[0]
        distance = path_length_list[0]
        route = path_list[0]
        for i in range(1, len(path_length_list)):
            # testing to see if any other path has a better time than the shortest one
            if path_length_list[i] <= time * 2 and path_time_list[i] < time:
                time = path_time_list[i]
                distance = path_length_list[i]
                route = path_list[i]
            else:
                break
        else:
            if k == len(path_length_list):
                # if the testing is not conclusive we take one more path in consideration
                return self.optimal_route(source, target, k + 1)
        return time, distance, route

    def print_optimal_route(self, source, target):
        time, distance, route = self.optimal_route(source, target)
        print(f"The optimal route between {source} and {target} "
              f"will take {time} minutes and spans over {distance} kilometers")
        if len(route) % 2 == 0:
            print(f"The friends will meet halfway between {route[len(route)//2 - 1]} and {route[len(route)//2 ]}")
        else:
            print(f"The friends will meet in {route[len(route)//2]}")

        print("The path is the following:")
        for city in route:
            print(city, end=" ")
        print("\n")
