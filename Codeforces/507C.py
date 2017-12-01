#AC
h,exit = map(int,input().split())
vis = 0
isLeft = True
L = 1
mid = 2**(h-1)
R = 2**h

while L!=R:
	if isLeft:
		if exit>=L and exit<=mid:
			# In range
			vis += 1
			h -= 1
			R = mid
			mid = (L+R)//2
		else:
			vis += (2**h)-1
	else:
		if exit>=mid+1 and exit<=R:
			# In range
			vis += 1
			h -= 1
			L = mid+1
			mid = (L+R)//2
		else:
			vis += (2**h)-1
	isLeft = not isLeft

print (vis)
