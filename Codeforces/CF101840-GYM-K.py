'''
AC

Notes:
- Max no of doals is at most = no of bodies
- The second choice isn't good (First choice is always better than it)
- It's better to use just one eye and one mouth than using two eyes
'''

with open('katryoshka.in', 'r') as f:
	T = int(f.readline())
	for t in range(1, T+1):
		n, m, k = [int(no) for no in f.readline().split()]
		print('Case {}: {}'.format(t, min(k, n if m>=n else m + (n-m)//2)))
