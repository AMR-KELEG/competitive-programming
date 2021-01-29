'''
AC

No of matches = No of teams - 1
'''
with open('lazy.in', 'r') as f:
	T = int(f.readline())
	for i in range(T):
		n_teams = int(f.readline())
		print('Case {}: {}'.format(i+1, n_teams-1))
