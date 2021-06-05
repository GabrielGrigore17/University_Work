import json
import random


class DataGenerator:
    def __init__(self, number_of_nodes=25, min_weight=1, max_weight=300, min_edges=25, max_edges=300):
        if number_of_nodes > 2:
            self.n = number_of_nodes
        else:
            self.n = 25
        if 10000 > min_weight > 1:
            self.min_w = min_weight
        else:
            self.min_w = 1
        if 10000 > max_weight > 1:
            self.max_w = max_weight
        else:
            self.max_w = 300
        if min_weight > max_weight:
            self.max_w = min_weight + 1
        if min_edges >= self.n:
            self.min_e = min_edges
        else:
            self.min_e = self.n + 1
        if max_edges < self.n * (self.n - 1) // 2:
            self.max_e = max_edges
        else:
            self.max_e = self.n * (self.n - 1) // 2 - 1

        self.e = random.randint(self.n, self.n * (self.n - 1) // 2)

    def json_dump_random_data(self, json_file):
        cities = []
        with open("cities.txt", 'r') as cities_file:
            for city in cities_file:
                cities.append(city)
        random_cities = random.choices(cities, weights=None, cum_weights=None, k=self.n)
        edges = []
        data = {}
        for edge in range(self.e):
            while True:
                source = random.choice(random_cities).strip()
                target = random.choice(random_cities).strip()
                if source == target:
                    continue
                if (source, target) in edges or (target, source) in edges:
                    continue
                edges.append((source, target))
                break

            data[f"{edge + 1}"] = {
                "source": f"{source}",
                "target": f"{target}",
                "weight": f"{random.randint(1, 300)}"
            }
        with open(json_file, 'w') as outfile:
            json.dump(data, outfile)
