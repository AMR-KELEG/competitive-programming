#AC
sumAfter = []
add = []
sign = ''
sol = []
N = 0
l = 0
def solve(indx,curVal):
	if indx==l:
		pass
	elif indx<0:
		if N==curVal:
			pass
		else:
			 solve(indx+1,curVal)
	else:
		mul=1
		if sign[l-indx-1]=='n':
			mul=-1
		if sol[indx]==-1:
			if N>curVal and curVal+sumAfter[indx+1]<N:
				solve(indx+1,curVal)
			elif N<curVal and curVal-sumAfter[indx+1]>N:
				solve(indx+1,curVal)
			else:
				sol[indx]=0
				solve(indx-1,curVal)
		elif sol[indx]==0:
			if N>curVal and curVal+sumAfter[indx+1]<N:
				sol[indx] = -1
				solve(indx+1,curVal)
			elif N<curVal and curVal-sumAfter[indx+1]>N:
				sol[indx] = -1
				solve(indx+1,curVal)
			else:
				sol[indx]=1
				solve(indx-1,curVal+(add[indx]*mul))
		elif sol[indx]==1:
			sol[indx]=-1
			solve(indx+1,curVal-(add[indx]*mul))

def prepare():
	val=1
	for it in range(65):
		add.append(val)
		sumAfter.append(val-1)
		val *= 2

t=int(input())
prepare()
for i in range(t):
	l=int(input())
	sign = input()
	N=int(input())
	sol = [-1 for x in range(l)]
	solve(l-1,0)
	if sol[0]==-1:
		print ('Impossible')
	else:
		for indx in range(l):
			print (sol[l-indx-1],end='')
		print()
