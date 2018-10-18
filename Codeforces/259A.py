#AC
import re

for i in range(8):
    s = input()
    if re.findall(r'(WW)|(BB)', s):
        print('NO')
        exit(0)

print('YES')
