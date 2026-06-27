import sys
def solve():
    try:
        sys.stdin = open('BAI9.INP', 'r')
        sys.stdout = open('BAI9.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    m = int(data[1])
    q = int(data[2])
    idx = 3
    d = [[0] * (m + 2) for _ in range(n + 2)]
    for _ in range(q):
        r1, c1, r2, c2, v = int(data[idx]), int(data[idx+1]), int(data[idx+2]), int(data[idx+3]), int(data[idx+4])
        idx += 5
        d[r1][c1] += v
        d[r2+1][c1] -= v
        d[r1][c2+1] -= v
        d[r2+1][c2+1] += v
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1]
    
    out = []
    for i in range(1, n + 1):
        out.append(' '.join(str(d[i][j]) for j in range(1, m + 1)))
    print('\n'.join(out))
solve()
