from route_generator import RouteGenerator


SMALL = RouteGenerator()
NORMAL = RouteGenerator()

SMALL.load_data("samples.json", "small_sample")
NORMAL.load_data("samples.json", "normal_sample")


time, distance, route = SMALL.optimal_route('A', 'G')
print(time)
print(distance)
print(route)

time, distance, route = NORMAL.optimal_route('Craiova', 'Oradea')
print(time)
print(distance)
print(route)
