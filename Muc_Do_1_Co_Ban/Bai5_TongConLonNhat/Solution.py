import sys
def solve():
    try:
        sys.stdin = open('BAI5.INP', 'r')
        sys.stdout = open('BAI5.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    arr = [int(x) for x in data[1:1+n]]
    max_sum = -float('inf')
    cur = 0
    for x in arr:
        cur = max(x, cur + x)
        max_sum = max(max_sum, cur)
    print(max_sum)
solve()
