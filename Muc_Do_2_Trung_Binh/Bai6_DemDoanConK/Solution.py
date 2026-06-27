import sys
def solve():
    try:
        sys.stdin = open('BAI6.INP', 'r')
        sys.stdout = open('BAI6.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    k = int(data[1])
    arr = [int(x) for x in data[2:2+n]]
    cur = 0
    ans = 0
    cnt = {0: 1}
    for x in arr:
        cur += x
        ans += cnt.get(cur - k, 0)
        cnt[cur] = cnt.get(cur, 0) + 1
    print(ans)
solve()
