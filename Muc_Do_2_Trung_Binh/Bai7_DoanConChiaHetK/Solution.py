import sys
def solve():
    try:
        sys.stdin = open('BAI7.INP', 'r')
        sys.stdout = open('BAI7.OUT', 'w')
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
        cur = (cur + x) % k
        cur = (cur + k) % k
        ans += cnt.get(cur, 0)
        cnt[cur] = cnt.get(cur, 0) + 1
    print(ans)
solve()
