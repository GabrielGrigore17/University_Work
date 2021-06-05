# from data_generator import DataGeneration
from data_generator import DataGenerator
file_1 = DataGenerator(number_of_nodes=50, min_edges=100, max_edges=1220)

file_1.json_dump_random_data("generated_data_2.json")
