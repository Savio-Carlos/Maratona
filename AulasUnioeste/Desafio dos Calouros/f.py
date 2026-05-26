from math import factorial
from itertools import product

def solve():
    n = int(input())
    c = list(map(int, input().split()))
    
    fat = [factorial(i) for i in range(9)]
    fat8 = factorial(8)
    
    ans = 0
    
    ranges = [range(min(ci, 8) + 1) for ci in c]
    
    for combo in product(*ranges):
        if sum(combo) == 8:
            mult = fat8
            for a in combo:
                mult //= fat[a]
            ans += mult
    
    print(ans)

solve()