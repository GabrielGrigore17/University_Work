from route_generator import RouteGenerator
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


#######################################################################################################################
#######################################################################################################################
#######################################################################################################################

# EXPERIMENTAL DATA SETS
# TEN SETS IN TOTAL RANGING FROM SMALL TO VERY LARGE

#######################################################################################################################
# SMALL
#######################################################################################################################

# SMALL_TEST_1 = RouteGenerator()
# SMALL_TEST_1.load_data("DataGeneration/generated_data_1_small.json", "data")
# SMALL_TEST_1.print_optimal_route('Dearborn', 'Greenbriar')
#
# SMALL_TEST_2 = RouteGenerator()
# SMALL_TEST_2.load_data("DataGeneration/generated_data_2_small.json", "data")
# SMALL_TEST_2.print_optimal_route('Dearborn', 'Greenbriar')
#
# SMALL_TEST_3 = RouteGenerator()
# SMALL_TEST_3.load_data("DataGeneration/generated_data_3_small.json", "data")
# SMALL_TEST_3.print_optimal_route('Dearborn', 'Greenbriar')

#######################################################################################################################
# MEDIUM
#######################################################################################################################

# MEDIUM_TEST_1 = RouteGenerator()
# MEDIUM_TEST_1.load_data("DataGeneration/generated_data_4_medium.json", "data")
# MEDIUM_TEST_1.print_optimal_route('Dearborn', 'Greenbriar')
#
# MEDIUM_TEST_2 = RouteGenerator()
# MEDIUM_TEST_2.load_data("DataGeneration/generated_data_5_medium.json", "data")
# MEDIUM_TEST_2.print_optimal_route('Dearborn', 'Greenbriar')
#
# MEDIUM_TEST_3 = RouteGenerator()
# MEDIUM_TEST_3.load_data("DataGeneration/generated_data_6_medium.json", "data")
# MEDIUM_TEST_3.print_optimal_route('Dearborn', 'Greenbriar')

#######################################################################################################################
# LARGE
#######################################################################################################################

# LARGE_TEST_1 = RouteGenerator()
# LARGE_TEST_1.load_data("DataGeneration/generated_data_7_large.json", "data")
# LARGE_TEST_1.print_optimal_route('Dearborn', 'Greenbriar')
#
# LARGE_TEST_2 = RouteGenerator()
# LARGE_TEST_2.load_data("DataGeneration/generated_data_8_large.json", "data")
# LARGE_TEST_2.print_optimal_route('Dearborn', 'Greenbriar')
#
# LARGE_TEST_3 = RouteGenerator()
# LARGE_TEST_3.load_data("DataGeneration/generated_data_9_large.json", "data")
# LARGE_TEST_3.print_optimal_route('Dearborn', 'Greenbriar')

#######################################################################################################################
# VERY LARGE
#######################################################################################################################

# VERY_LARGE_TEST = RouteGenerator()
# VERY_LARGE_TEST.load_data("DataGeneration/generated_data_10_very_large.json", "data")
# VERY_LARGE_TEST.print_optimal_route('Dearborn', 'Greenbriar')

#######################################################################################################################
