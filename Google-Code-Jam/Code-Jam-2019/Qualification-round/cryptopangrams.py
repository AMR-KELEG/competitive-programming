# Passed all test sets

import math

if __name__ == '__main__':
    T = int(input())
    for t in range(1, 1+T):
        line = input()
        N, L = [int(i) for i in line.split()]

        line = input()
        nos = [int(i) for i in line.split()]

        i = 0
        while nos[i] == nos[i+1]:
        	i += 1
        vals = [0]* (L+1)

        vals[i+1] = math.gcd(nos[i], nos[i + 1])
        j = i
        while j >= 0:
        	vals[j] = nos[j] // vals[j+1]
        	j -= 1
        
        j = i + 1
        while j < L:
        	vals[j+1] = nos[j] // vals[j]
        	j += 1

        unique_primes = list(set(vals))
        unique_primes.sort()
        d = {int(v):chr(ord('A')+i) for i, v in enumerate(unique_primes)}
        print('Case #{}: {}'.format(t, ''.join([d[int(v)] for v in vals])))
