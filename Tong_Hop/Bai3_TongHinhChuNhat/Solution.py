import sys
def solve():
    try: sys.stdin = open('BAI3.INP', 'r'); sys.stdout = open('BAI3.OUT', 'w')
    except: pass
    data = sys.stdin.read().split()
    if not data: return
    n, m, q = int(data[0]), int(data[1]), int(data[2])
    idx = 3
    pref = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            x = int(data[idx]); idx += 1
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + x
    out = []
    for _ in range(q):
        r1, c1, r2, c2 = int(data[idx]), int(data[idx+1]), int(data[idx+2]), int(data[idx+3])
        idx += 4
        ans = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1]
        out.append(str(ans))
    print('\n'.join(out))
solve()
