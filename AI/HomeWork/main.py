from route_generator import RouteGenerator
from timeit import timeit
#######################################################################################################################

# DEMO

#######################################################################################################################

SMALL = RouteGenerator()
NORMAL = RouteGenerator()
LARGE = RouteGenerator()
VERY_LARGE = RouteGenerator()

SMALL.load_data("samples.json", "small_sample")  # 12 nodes 12 edges example demonstrating special case
NORMAL.load_data("samples.json", "normal_sample")  # 20 nodes 23 edges Romania Map From Example
LARGE.load_data("samples.json", "large_sample")  # 50 nodes 296 edges auto generated
VERY_LARGE.load_data("samples.json", "very_large_sample")  # 500 nodes 1325 edges auto generated


SMALL.print_optimal_route('A', 'G')

NORMAL.print_optimal_route('Craiova', 'Oradea')

LARGE.print_optimal_route('Penzance', 'Davie')

VERY_LARGE.print_optimal_route('Bumba', 'Bhubaneshwar')

print(timeit())


#######################################################################################################################
#######################################################################################################################
#######################################################################################################################

# EXPERIMENTAL DATA SETS
# TEN SETS IN TOTAL RANGING FROM SMALL TO VERY LARGE WITH RANDOMIZED EDGE NUMBERS

#######################################################################################################################
# SMALL
#######################################################################################################################

# SMALL_TEST_1 = RouteGenerator()  # 10 nodes
# SMALL_TEST_1.load_data("DataGeneration/generated_data_1_small.json", "data")
# SMALL_TEST_1.print_optimal_route('Dearborn', 'Greenbriar')
# print(timeit())
#
# SMALL_TEST_2 = RouteGenerator()  # 15 nodes
# SMALL_TEST_2.load_data("DataGeneration/generated_data_2_small.json", "data")
# SMALL_TEST_2.print_optimal_route('Bargoed', 'Kurdamir')
# print(timeit())
#
# SMALL_TEST_3 = RouteGenerator()  # 20 nodes
# SMALL_TEST_3.load_data("DataGeneration/generated_data_3_small.json", "data")
# SMALL_TEST_3.print_optimal_route('Balqash', 'Haora')
# print(timeit())

#######################################################################################################################
# MEDIUM
#######################################################################################################################

# MEDIUM_TEST_1 = RouteGenerator()  # 40 nodes
# MEDIUM_TEST_1.load_data("DataGeneration/generated_data_4_medium.json", "data")
# MEDIUM_TEST_1.print_optimal_route('Frimley', 'Malabon')
# print(timeit())
#
# MEDIUM_TEST_2 = RouteGenerator()  # 60 nodes
# MEDIUM_TEST_2.load_data("DataGeneration/generated_data_5_medium.json", "data")
# MEDIUM_TEST_2.print_optimal_route('Dinnington', 'Nalut')
# print(timeit())
#
# MEDIUM_TEST_3 = RouteGenerator()  # 80 nodes
# MEDIUM_TEST_3.load_data("DataGeneration/generated_data_6_medium.json", "data")
# MEDIUM_TEST_3.print_optimal_route('Toledo', 'Everett')
# print(timeit())

#######################################################################################################################
# LARGE
#######################################################################################################################

# LARGE_TEST_1 = RouteGenerator()  # 150 nodes
# LARGE_TEST_1.load_data("DataGeneration/generated_data_7_large.json", "data")
# LARGE_TEST_1.print_optimal_route('Hechi', 'Stopsley')
# print(timeit())
#
# LARGE_TEST_2 = RouteGenerator()  # 200 nodes
# LARGE_TEST_2.load_data("DataGeneration/generated_data_8_large.json", "data")
# LARGE_TEST_2.print_optimal_route('Charsadda', 'Durgapur')
# print(timeit())
#
# LARGE_TEST_3 = RouteGenerator()  # 250 nodes
# LARGE_TEST_3.load_data("DataGeneration/generated_data_9_large.json", "data")
# LARGE_TEST_3.print_optimal_route('Goranboy', 'Uruguaiana')
# print(timeit())

#######################################################################################################################
# VERY LARGE
#######################################################################################################################

# VERY_LARGE_TEST = RouteGenerator()  # 5000 nodes
# VERY_LARGE_TEST.load_data("DataGeneration/generated_data_10_very_large.json", "data")
# VERY_LARGE_TEST.print_optimal_route('Monclova', 'Pushkino')
# print(timeit())

#######################################################################################################################
