# AC

def is_sort_correct(n, a):
	for _ in range(n):
		# find argmax
		max_indx = a.index(max(a))
		if max_indx +1 != len(a):
			if abs(a[max_indx] - a[max_indx+1]) >1:
				return False
		if max_indx != 0:
			if abs(a[max_indx] - a[max_indx-1]) >1:
				return False
		a.pop(max_indx)
	return True

n = int(input())
a = [int(ai) for ai in input().split()]

print('YES' if is_sort_correct(n, a) else 'NO')
