import networkx as nx
import copy as cp


def k_shortest_paths(G, source, target, k=1, weight='weight'):
    # G is a networkx graph.
    # source and target are the labels for the source and target of the path.
    # k is the amount of desired paths.
    # weight = 'weight' assumes a weighed graph. If this is undesired, use weight = None.

    A = [nx.dijkstra_path(G, source, target, weight='weight')]
    A_len = [sum([G[A[0][l]][A[0][l + 1]]['weight'] for l in range(len(A[0]) - 1)])]
    # A_time = [sum([max(G[A[0][l]][A[0][l + 1]]['weight'], G[A[0][l]][A[0][len(A[0]) - 1]]['weight'])
    #           for l in range((len(A[0]) - 1)//2)])]
    time_sum = 0
    for i in range((len(A[0]) - 1)//2):
        time_sum += max(G[A[0][i]][A[0][i + 1]]['weight'],
                        G[A[0][len(A[0]) - i - 1]][A[0][len(A[0]) - i - 2]]['weight'])
    if (len(A[0]) - 1) % 2 == 1:
        time_sum += G[A[0][(len(A[0]) - 1) % 2]][A[0][(len(A[0]) - 1) % 2 + 1]]['weight'] / 2

    A_time = [time_sum]

    B = []

    for i in range(1, k):
        for j in range(0, len(A[-1]) - 1):
            Gcopy = cp.deepcopy(G)
            spur_node = A[-1][j]
            rootpath = A[-1][:j + 1]
            for path in A:
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
        lenB = [sum([G[path[l]][path[l + 1]]['weight'] for l in range(len(path) - 1)]) for path in B]
        B = [p for _, p in sorted(zip(lenB, B))]

        for path in B:
            time_sum = 0
            for i in range((len(path) - 1)//2):
                time_sum += max(G[path[i]][path[i + 1]]['weight'],
                                G[path[len(path) - i - 1]][path[len(path) - i - 2]]['weight'])
            if (len(path) - 1) % 2 == 1:
                time_sum += G[path[(len(path) - 1) % 2]][path[(len(path) - 1) % 2 + 1]]['weight'] / 2
            A_time.append(time_sum)


        A.append(B[0])
        A_len.append(sorted(lenB)[0])
        B.remove(B[0])

    return A, A_len, A_time