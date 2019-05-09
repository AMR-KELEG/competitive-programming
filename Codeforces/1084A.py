# AC
def req_elec(cap, x):
	return 2 * sum([c*(abs(x-f) + f + x) for f, c in enumerate(cap)])

n_floors = int(input())
cap_per_floor = [int(c) for c in input().split()]

print(min([req_elec(cap_per_floor, x) for x in range(n_floors)]))
