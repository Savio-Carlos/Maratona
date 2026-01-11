#!/usr/bin/env python3
import random
import sys
MAXC = 10**9

def rand_point(n):
    # mix: some with y==1, some with y random up to 20, cluster some x
    pts = set()
    # add some structured hard cases
    # 1) rectangle corners
    if random.random() < 0.2:
        x1 = random.randint(1, 1000)
        y1 = random.randint(1, 1000)
        x2 = x1 + random.randint(1, 50)
        y2 = y1 + random.randint(1, 50)
        pts |= {(x1,y1),(x1,y2),(x2,y1),(x2,y2)}
    # 2) column clusters
    if random.random() < 0.6:
        cols = random.randint(1,8)
        for _ in range(cols):
            cx = random.randint(1,1000)
            cnt = random.randint(1,6)
            for j in range(cnt):
                # some at y=1
                if random.random() < 0.3:
                    y = 1
                else:
                    y = random.randint(2,50)
                pts.add((cx, y))
    # 3) zig-zag
    if random.random() < 0.3:
        m = random.randint(4,12)
        for i in range(1,m+1):
            x = 10000 + i
            y = 3 if i%2 else 1
            pts.add((x,y))
    # 4) large gaps + extremes
    if random.random() < 0.3:
        pts.add((1, random.randint(1,50)))
        pts.add((MAXC, random.randint(1,50)))
        pts.add((random.randint(1,100), 1))
    # fill random points until desired n
    while len(pts) < n:
        x = random.randint(1, 1000000)  # keep coords moderate mostly
        y = 1 if random.random() < 0.35 else random.randint(2, 100)
        pts.add((x,y))
    pts = list(pts)[:n]
    return pts

if __name__ == "__main__":
    random.seed(int(sys.argv[1]) if len(sys.argv)>1 else None)
    # generate several tests:
    T = 200
    for t in range(T):
        n = random.randint(3, 200)  # vary N up to 200 for speed; change to 1000 for full stress
        pts = rand_point(n)
        print(n)
        for x,y in pts:
            print(x, y)
        # separator between tests is not necessary: each test will be redirected individually by harness
        # to run a single test, redirect only one block
        if t != T-1:
            pass
