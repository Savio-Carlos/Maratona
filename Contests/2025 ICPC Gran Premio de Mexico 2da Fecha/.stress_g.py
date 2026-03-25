import random, itertools, subprocess

random.seed(2)

def inside_strict(a,b,c,p,eps=1e-12):
    def cross(u,v,w):
        return (v[0]-u[0])*(w[1]-u[1]) - (v[1]-u[1])*(w[0]-u[0])
    c1 = cross(a,b,p)
    c2 = cross(b,c,p)
    c3 = cross(c,a,p)
    return (c1>eps and c2>eps and c3>eps) or (c1<-eps and c2<-eps and c3<-eps)

def brute(islands,h,cookie):
    best = {}
    for x,y,z in islands:
        key=(x,y)
        if key not in best or z>best[key]:
            best[key]=z
    pts=[(x,y,z) for (x,y),z in best.items() if not (abs(x-cookie[0])<1e-12 and abs(y-cookie[1])<1e-12)]
    if not pts:
        return None
    levels=sorted(set(z for _,_,z in pts))

    def check(level):
        avail=[(x,y) for x,y,z in pts if z+1e-12>=level]
        if len(avail)<3:
            return False
        for i,j,k in itertools.combinations(range(len(avail)),3):
            if inside_strict(avail[i],avail[j],avail[k],cookie):
                return True
        return False

    feasible=[lv for lv in levels if check(lv)]
    if not feasible:
        return None
    best_level=max(feasible)
    return max(0.0,h-best_level)

def run_prog(islands,h,cookie):
    lines=[f"{len(islands)} {h:.2f}"]
    for x,y,z in islands:
        lines.append(f"{x:.2f} {y:.2f} {z:.2f}")
    lines.append(f"{cookie[0]:.2f} {cookie[1]:.2f}")
    inp='\n'.join(lines)+'\n'
    out=subprocess.check_output(['./g.exe'], input=inp.encode()).decode().strip()
    return None if out=='-1' else float(out)

for tc in range(2000):
    n=random.randint(1,9)
    h=round(random.uniform(1,40),2)
    cookie=(round(random.uniform(-4,4),2), round(random.uniform(-4,4),2))
    islands=[]
    for _ in range(n):
        islands.append((round(random.uniform(-4,4),2), round(random.uniform(-4,4),2), round(random.uniform(-15,40),2)))
    if n>=2 and random.random()<0.35:
        i=random.randrange(n)
        x,y,_=islands[i]
        islands.append((x,y,round(random.uniform(-15,40),2)))

    b=brute(islands,h,cookie)
    p=run_prog(islands,h,cookie)

    if (b is None) != (p is None):
        print('MISMATCH_TYPE', tc, b, p)
        print('h', h, 'cookie', cookie)
        print('islands', islands)
        raise SystemExit(1)
    if b is not None and abs(b-p) > 1e-6*max(1.0,abs(b)) + 1e-7:
        print('MISMATCH_VALUE', tc, b, p)
        print('h', h, 'cookie', cookie)
        print('islands', islands)
        raise SystemExit(1)

print('OK 2000')
