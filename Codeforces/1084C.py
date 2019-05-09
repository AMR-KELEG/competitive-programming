# AC
import re

s = input()
s = re.sub(r'[^a-b]', '', s)
s = re.sub(r'b+', 'b', s)

next_b = [len(s)-1 for _ in range(len(s))]

last_b_index = -1
i = len(s) - 1
while i>=0:
	if last_b_index !=-1:
		next_b[i] = last_b_index
	if s[i] == 'b':
		last_b_index = i
	i -= 1

dp = [-1 for _ in range(len(s)+1)]
dp[len(s)] = 0
i = len(s) - 1

while i>=0:
	dp[i] = dp[i + 1]
	if s[i] == 'a':
		dp[i] += 1 + (dp[next_b[i]+1])
		dp[i] %= 1000000007
	i -= 1
print(dp[0])
