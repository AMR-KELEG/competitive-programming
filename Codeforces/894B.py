# AC
def mod_pow(val, p, MOD):
	if p==0:
		return 1
	if p==1:
		return val
	res = mod_pow(val, p>>1, MOD)
	res = res * res
	res %= MOD
	if p%2:
		res = (val*res) % MOD
	return res

n, m ,k = [int(i) for i in input().split()]

if k==-1 and (n%2 != m%2):
	print(0)
else:
	print(mod_pow(2, (n-1)*(m-1), 1000000007))
