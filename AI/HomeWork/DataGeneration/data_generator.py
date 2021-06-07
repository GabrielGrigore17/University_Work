import json
import random


class DataGenerator:
    def __init__(self, number_of_nodes=25, min_weight=50, max_weight=300, min_edges=25, max_edges=300):
        if number_of_nodes > 2:
            self.n = number_of_nodes
        else:
            self.n = 25
        if 10000 > min_weight > 1:
            self.min_w = min_weight
        else:
            self.min_w = 50
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
        if self.min_e < max_edges < self.n * (self.n - 1) // 2:
            self.max_e = max_edges
        else:
            self.max_e = self.n * (self.n - 1) // 2 - 1

        self.e = random.randint(self.min_e, self.max_e)

    def json_dump_random_data(self, json_file):
        cities = []  # list to store all the cities in cities.txt
        with open("cities.txt", 'r') as cities_file:
            for city in cities_file:
                cities.append(city)
        # a list of n cities selected randomly
        random_cities = random.choices(cities, weights=None, cum_weights=None, k=self.n)
        edges = []
        # the dictionary that will be stored in the json file
        data = {"data": {}}
        for edge in range(self.e):
            while True:
                # selecting to cities and stripping off the \n character
                source = random.choice(random_cities).strip()
                target = random.choice(random_cities).strip()
                if source == target:  # check for the same city
                    continue
                if (source, target) in edges or (target, source) in edges:  # check if edge exists
                    continue
                edges.append((source, target))  # storing edge if everything is ok
                break

            # adding every edge and assigning it a random weight within the interval
            data["data"][f"{edge + 1}"] = {
                "source": f"{source}",
                "target": f"{target}",
                "weight": f"{random.randint(self.min_w, self.max_w)}"
            }
        with open(json_file, 'w') as outfile:  # dumping the dict into the json file
            json.dump(data, outfile)


# SMALL
#######################################################################################################################
file_1 = DataGenerator(number_of_nodes=10, min_weight=50, max_weight=400, min_edges=11, max_edges=16)

file_1.json_dump_random_data("generated_data_1.json")

file_2 = DataGenerator(number_of_nodes=15, min_weight=50, max_weight=400, min_edges=20, max_edges=30)

file_2.json_dump_random_data("generated_data_2.json")

file_3 = DataGenerator(number_of_nodes=20, min_weight=50, max_weight=400, min_edges=25, max_edges=40)

file_3.json_dump_random_data("generated_data_3.json")
#######################################################################################################################
# MEDIUM
#######################################################################################################################
file_4 = DataGenerator(number_of_nodes=40, min_weight=100, max_weight=400, min_edges=100, max_edges=150)

file_4.json_dump_random_data("generated_data_4.json")

file_5 = DataGenerator(number_of_nodes=60, min_weight=100, max_weight=400, min_edges=120, max_edges=160)

file_5.json_dump_random_data("generated_data_5.json")

file_6 = DataGenerator(number_of_nodes=80, min_weight=100, max_weight=400, min_edges=150, max_edges=200)

file_6.json_dump_random_data("generated_data_6.json")
#######################################################################################################################
# LARGE
#######################################################################################################################
file_7 = DataGenerator(number_of_nodes=150, min_weight=100, max_weight=400, min_edges=250, max_edges=400)

file_7.json_dump_random_data("generated_data_7.json")

file_8 = DataGenerator(number_of_nodes=200, min_weight=100, max_weight=400, min_edges=300, max_edges=500)

file_8.json_dump_random_data("generated_data_8.json")

file_9 = DataGenerator(number_of_nodes=250, min_weight=100, max_weight=400, min_edges=400, max_edges=700)

file_9.json_dump_random_data("generated_data_9.json")
#######################################################################################################################
# VERY LARGE
#######################################################################################################################
file_10 = DataGenerator(number_of_nodes=5000, min_weight=100, max_weight=400, min_edges=10000, max_edges=12000)

file_10.json_dump_random_data("generated_data_10.json")
