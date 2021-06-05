from route_generator import RouteGenerator


SMALL = RouteGenerator()
NORMAL = RouteGenerator()
LARGE = RouteGenerator()

SMALL.load_data("samples.json", "small_sample")
NORMAL.load_data("samples.json", "normal_sample")
LARGE.load_data("samples.json", "large_sample")


SMALL.print_optimal_route('A', 'G')

NORMAL.print_optimal_route('Craiova', 'Oradea')

LARGE.print_optimal_route('Gastonia', 'Osorio')
