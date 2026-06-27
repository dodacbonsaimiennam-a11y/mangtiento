import sys
def solve():
    try: sys.stdin = open('BAI2.INP', 'r'); sys.stdout = open('BAI2.OUT', 'w')
    except: pass
    data = sys.stdin.read().split()
    if not data: return
    n, k = int(data[0]), int(data[1])
    arr = [int(x) for x in data[2:2+n]]
    cur = ans = 0
    cnt = {0: 1}
    for x in arr:
        cur += x
        ans += cnt.get(cur - k, 0)
        cnt[cur] = cnt.get(cur, 0) + 1
    print(ans)
solve()
