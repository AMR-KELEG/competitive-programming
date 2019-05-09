# AC
import math

ax, ay, bx, by, tx, ty = [int(coord) for coord in input().split()]
n = int(input())
x ,y = [], []

minDis = 0
diff1 = []
diff2 = []

for i in range(n):
	xi, yi = [int(coord) for coord in input().split()]
	x.append(xi)
	y.append(yi)
	disBin = math.sqrt((xi-tx)**2 + (yi-ty)**2)
	diff1.append(( math.sqrt((ax-xi)**2 + (ay-yi)**2) - disBin, i))
	diff2.append(( math.sqrt((bx-xi)**2 + (by-yi)**2) - disBin, i))
	minDis += 2 * disBin

diff1.sort()
diff2.sort()

ans = min(minDis + diff1[0][0], minDis + diff2[0][0])

if diff1[0][1] != diff2[0][1]:
	ans = min(ans, minDis + diff1[0][0] + diff2[0][0])

elif n>1:
	ans = min(ans, minDis + diff1[0][0] + diff2[1][0])
	ans = min(ans, minDis + diff1[1][0] + diff2[0][0])

print(ans)
