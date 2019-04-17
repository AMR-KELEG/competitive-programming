# Passed all test sets
# The main idea is to just reverse each operation (E->S and S->E)
def reverse_str(s):
	return ''.join(['S' if c =='E' else 'E' for c in s])

if __name__ == '__main__':
	T = int(input())
	for t in range(1, 1+T):
		input()
		print('Case #{}: {}'.format(t, reverse_str(input())))
