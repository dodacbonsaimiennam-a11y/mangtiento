import sys
def solve():
    try:
        sys.stdin = open('BAI3.INP', 'r')
        sys.stdout = open('BAI3.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    q = int(data[1])
    arr = [int(x) for x in data[2:2+n]]
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i+1] = pref[i] ^ arr[i]
    idx = 2 + n
    out = []
    for _ in range(q):
        l = int(data[idx])
        r = int(data[idx+1])
        idx += 2
        out.append(str(pref[r] ^ pref[l-1]))
    print('\n'.join(out))
solve()
