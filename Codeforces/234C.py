# AC
# IMPLEMENTATION
# 0 always need to be modified
with open('input.txt', 'r') as f:
	n = int(f.readline())
	temp = [int(t) for t in f.readline().split()]

count_pos_left = []
n_pos_left = 0
for i in range(0, n):
	count_pos_left.append(n_pos_left)
	if temp[i] >= 0:
		n_pos_left += 1

count_neg_right = []
n_neg_right = 0
for i in range(n-1, -1, -1):
	count_neg_right.append(n_neg_right)
	if temp[i] <= 0:
		n_neg_right += 1
count_neg_right.reverse()

ans = n
for i in range(1, n-1):
	ans = min(ans, count_pos_left[i] + count_neg_right[i] - (1 if temp[i]==0 else 0))

ans = min(ans, count_neg_right[0] + (1 if temp[0]>=0 else 0))
ans = min(ans, count_pos_left[n-1] + (1 if temp[n-1]<=0 else 0))

with open('output.txt', 'w') as f:
	f.write(str(ans))
