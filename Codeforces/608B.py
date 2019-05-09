# AC
a = input()
b = input()

cs_one = [0]
for ai in a:
	cs_one.append(cs_one[-1] + int(ai=='1'))

def find_zeros_ones_in_range(l, r):
	n_ones = cs_one[r+1] - cs_one[l]
	n_zeros = (r-l+1) - n_ones
	return n_zeros, n_ones

sum_hamming_dis = 0

for i, bi in enumerate(b):
	n_before = i
	n_after = len(b) - n_before - 1
	l = max(len(a) - 1 - n_after, 0)
	r = min(n_before, len(a) -1)
	nz, no = find_zeros_ones_in_range(l, r)
	if bi == '0':
		sum_hamming_dis += no
	else:
		sum_hamming_dis += nz

print(sum_hamming_dis)
