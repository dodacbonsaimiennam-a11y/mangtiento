import sys
def solve():
    try:
        sys.stdin = open('BAI15.INP', 'r')
        sys.stdout = open('BAI15.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    arr = [int(x) for x in data[1:1+n]]
    arr.sort()
    ans = 0
    for i in range(n):
        ans += arr[i] * (2 * i - n + 1)
    print(ans)
solve()
