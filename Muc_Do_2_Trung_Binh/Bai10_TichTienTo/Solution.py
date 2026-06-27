import sys
def solve():
    try:
        sys.stdin = open('BAI10.INP', 'r')
        sys.stdout = open('BAI10.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    q = int(data[1])
    p = int(data[2])
    idx = 3
    pref = [1] * (n + 1)
    for i in range(1, n + 1):
        x = int(data[idx])
        idx += 1
        pref[i] = (pref[i-1] * x) % p
    out = []
    for _ in range(q):
        l = int(data[idx])
        r = int(data[idx+1])
        idx += 2
        num = pref[r]
        den = pref[l-1]
        inv = pow(den, p - 2, p)
        ans = (num * inv) % p
        out.append(str(ans))
    print('\n'.join(out))
solve()
