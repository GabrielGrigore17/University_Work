import networkx as nx
import copy as cp


class RouteGenerator(nx.Graph):

    def __init__(self):
        nx.Graph.__init__(self)

    def k_shortest_paths(self, source, target, k=1, weight='weight'):
        # G is a networkx graph.
        # source and target are the labels for the source and target of the path.
        # k is the amount of desired paths.
        # weight = 'weight' assumes a weighed graph. If this is undesired, use weight = None.

        path_list = [nx.dijkstra_path(self, source, target, weight='weight')]
        path_length_list = [sum([self[path_list[0][i]][path_list[0][i + 1]]['weight']
                                 for i in range(len(path_list[0]) - 1)])]

        time_sum = 0
        for i in range((len(path_list[0]) - 1) // 2):
            time_sum += max(self[path_list[0][i]][path_list[0][i + 1]]['weight'],
                            self[path_list[0][len(path_list[0]) - i - 1]]
                            [path_list[0][len(path_list[0]) - i - 2]]['weight'])
        if (len(path_list[0]) - 1) % 2 == 1:
            time_sum += self[path_list[0][(len(path_list[0]) - 1) % 2]][path_list[0]
            [(len(path_list[0]) - 1) % 2 + 1]]['weight'] / 2

        path_time_list = [time_sum]

        max_time = time_sum

        B = []

        for i in range(1, k):
            for j in range(0, len(path_list[-1]) - 1):
                Gcopy = cp.deepcopy(self)
                spur_node = path_list[-1][j]
                rootpath = path_list[-1][:j + 1]
                for path in path_list:
                    if rootpath == path[0:j + 1]:  # and len(path) > j?
                        if Gcopy.has_edge(path[j], path[j + 1]):
                            Gcopy.remove_edge(path[j], path[j + 1])
                        if Gcopy.has_edge(path[j + 1], path[j]):
                            Gcopy.remove_edge(path[j + 1], path[j])
                for n in rootpath:
                    if n != spur_node:
                        Gcopy.remove_node(n)
                try:
                    spurpath = nx.dijkstra_path(Gcopy, spur_node, target, weight='weight')
                    totalpath = rootpath + spurpath[1:]
                    if totalpath not in B:
                        B += [totalpath]
                except nx.NetworkXNoPath:
                    continue
            if len(B) == 0:
                break
            lenB = [sum([self[path[l]][path[l + 1]]['weight'] for l in range(len(path) - 1)]) for path in B]
            B = [p for _, p in sorted(zip(lenB, B))]

            for path in B:
                time_sum = 0
                for i in range((len(path) - 1) // 2):
                    time_sum += max(self[path[i]][path[i + 1]]['weight'],
                                    self[path[len(path) - i - 1]][path[len(path) - i - 2]]['weight'])
                if (len(path) - 1) % 2 == 1:
                    time_sum += self[path[(len(path) - 1) % 2]][path[(len(path) - 1) % 2 + 1]]['weight'] / 2
                path_time_list.append(time_sum)

            path_list.append(B[0])
            path_length_list.append(sorted(lenB)[0])
            B.remove(B[0])

        return path_list, path_length_list, path_time_list

    def optimal_route(self, source, target, k=3):
        A, A_len, A_time = self.k_shortest_paths(source, target, k)
        time = A_time[0]
        distance = A_len[0]
        route = A[0]
        for i in range(1, len(A_len)):
            if A_len[i] <= time * 2 and A_time[i] < time:
                time = A_time[i]
                distance = A_len[i]
                route = A[i]
            else:
                break
        else:
            if k == len(A_len):
                return self.optimal_route(source, target, k + 1)
        return time, distance, route
