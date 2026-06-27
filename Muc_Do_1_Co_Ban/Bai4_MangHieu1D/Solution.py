import sys
def solve():
    try:
        sys.stdin = open('BAI4.INP', 'r')
        sys.stdout = open('BAI4.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    q = int(data[1])
    idx = 2
    d = [0] * (n + 2)
    for _ in range(q):
        l = int(data[idx])
        r = int(data[idx+1])
        v = int(data[idx+2])
        idx += 3
        d[l] += v
        d[r+1] -= v
    cur = 0
    ans = []
    for i in range(1, n + 1):
        cur += d[i]
        ans.append(str(cur))
    print(' '.join(ans))
solve()
