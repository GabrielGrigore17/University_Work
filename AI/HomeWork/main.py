import networkx as nx
import json
from route_generator import optimal_route


file = open("samples.json")

sample = json.load(file)

SMALL = nx.Graph()
NORMAL = nx.Graph()

for edge in sample["small_sample"]:
    SMALL.add_edge(
        sample["small_sample"][edge]['source'],
        sample["small_sample"][edge]['target'],
        weight=int(sample["small_sample"][edge]['weight'])
    )

for edge in sample["normal_sample"]:
    NORMAL.add_edge(
        sample["normal_sample"][edge]['source'],
        sample["normal_sample"][edge]['target'],
        weight=int(sample["normal_sample"][edge]['weight'])
    )

time, distance, route = optimal_route(SMALL, 'A', 'G')
print(time)
print(distance)
print(route)

time, distance, route = optimal_route(NORMAL, 'Craiova', 'Oradea')
print(time)
print(distance)
print(route)


file.close()
