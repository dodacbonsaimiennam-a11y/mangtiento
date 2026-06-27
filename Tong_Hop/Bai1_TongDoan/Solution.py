import sys
def solve():
    try: sys.stdin = open('BAI1.INP', 'r'); sys.stdout = open('BAI1.OUT', 'w')
    except: pass
    data = sys.stdin.read().split()
    if not data: return
    n, q = int(data[0]), int(data[1])
    arr = [int(x) for x in data[2:2+n]]
    pref = [0] * (n + 1)
    for i in range(n): pref[i+1] = pref[i] + arr[i]
    idx = 2 + n
    out = []
    for _ in range(q):
        l, r = int(data[idx]), int(data[idx+1])
        idx += 2
        out.append(str(pref[r] - pref[l-1]))
    print('\n'.join(out))
solve()
