import sys
def solve():
    try:
        sys.stdin = open('BAI17.INP', 'r')
        sys.stdout = open('BAI17.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    m = int(data[1])
    k = int(data[2])
    idx = 3
    arr = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            arr[i][j] = arr[i][j-1] + int(data[idx])
            idx += 1
    
    ans = 0
    for c1 in range(1, m + 1):
        for c2 in range(c1, m + 1):
            cnt = {0: 1}
            cur = 0
            for r in range(1, n + 1):
                cur += arr[r][c2] - arr[r][c1-1]
                ans += cnt.get(cur - k, 0)
                cnt[cur] = cnt.get(cur, 0) + 1
    print(ans)
solve()
