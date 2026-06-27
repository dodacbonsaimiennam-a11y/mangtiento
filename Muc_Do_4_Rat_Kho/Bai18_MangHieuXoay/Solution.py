import sys
def solve():
    try:
        sys.stdin = open('BAI18.INP', 'r')
        sys.stdout = open('BAI18.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    m = int(data[1])
    q = int(data[2])
    idx = 3
    MAXU = n + m + 2
    MAXV = n + m + 2
    d_arr = [[0] * (MAXV + 2) for _ in range(MAXU + 2)]
    for _ in range(q):
        r = int(data[idx])
        c = int(data[idx+1])
        d = int(data[idx+2])
        v = int(data[idx+3])
        idx += 4
        
        u1 = max(1, r + c - d)
        u2 = min(MAXU, r + c + d)
        v1 = max(1, r - c + m - d)
        v2 = min(MAXV, r - c + m + d)
        
        if u1 <= u2 and v1 <= v2:
            d_arr[u1][v1] += v
            d_arr[u2+1][v1] -= v
            d_arr[u1][v2+1] -= v
            d_arr[u2+1][v2+1] += v
            
    for i in range(1, MAXU + 1):
        for j in range(1, MAXV + 1):
            d_arr[i][j] += d_arr[i-1][j] + d_arr[i][j-1] - d_arr[i-1][j-1]
            
    out = []
    for i in range(1, n + 1):
        out.append(' '.join(str(d_arr[i+j][i-j+m]) for j in range(1, m + 1)))
    print('\n'.join(out))
solve()
