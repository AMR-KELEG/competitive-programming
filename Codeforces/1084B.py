# AC
from math import ceil

n, s = [int(no) for no in input().split()]
v = [int(no) for no in input().split()]

min_v = min(v)
current_available = sum([vi - min_v for vi in v])

if current_available >= s:
	print(min_v)
else:
	rem = s - current_available
	# We have n kegs with min_v each
	# n * take >= rem
	# take >= rem/n
	# take = ceil(rem/n)
	# take must be <min_v
	req = ceil(rem / n)
	if req <= min_v:
		print(min_v - req)
	else:
		print(-1)
