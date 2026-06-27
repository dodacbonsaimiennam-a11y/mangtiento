import sys
def solve():
    try:
        sys.stdin = open('BAI2.INP', 'r')
        sys.stdout = open('BAI2.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    arr = [int(x) for x in data[1:1+n]]
    total = sum(arr)
    left = 0
    ans = -1
    for i in range(n):
        if left == total - left - arr[i]:
            ans = i + 1
            break
        left += arr[i]
    print(ans)
solve()
