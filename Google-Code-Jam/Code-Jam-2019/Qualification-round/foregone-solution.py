# Passed all test sets
# The solution will only divide each 4 into two 2s (one for each value A, B)
# The function clean_str will just remove any leading zeros in the string

import re 

def clean_str(s):
	return re.sub(r'^0+', '', ''.join(s))

def generate_pair(n):
	A = ['0'] * len(n)
	B = ['0'] * len(n)
	for i, v in enumerate(n):
		if v == '4':
			A[i] = '2'
			B[i] = '2'
		else:
			A[i] = v
	return clean_str(A), clean_str(B)

if __name__ == '__main__':
	T = int(input())

	for t in range(1, 1+T):
		n = input()
		A, B = generate_pair(n)
		print('Case #{}: {} {}'.format(t, A, B))
