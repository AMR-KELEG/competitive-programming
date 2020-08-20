def path_found(s, e, I, O, N, direction):
	if s == e:
		return True

	if O[s] == 'Y' and s+direction >=0 and s+direction < N and I[s+direction] == 'Y':
		return path_found(s+direction, e, I, O, N, direction)

	return False

def can_travel(s, e, I, O, N):
	if(path_found(s, e, I, O, N, +1) or
	   path_found(s, e, I, O, N, -1)):
		return 'Y'
	return 'N'

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		N = int(input())
		I = input().strip()
		O = input().strip()

		trips = [[None for _ in range(N)] for __ in range(N)]
		for s in range(N):
			for e in range(N):
				trips[s][e] = can_travel(s, e, I, O, N)

		print(f'Case #{t+1}:')
		print('\n'.join([''.join(l) for l in trips]))
