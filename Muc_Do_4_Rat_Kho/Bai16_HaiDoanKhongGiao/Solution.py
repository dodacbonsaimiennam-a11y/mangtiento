import sys
def solve():
    try:
        sys.stdin = open('BAI16.INP', 'r')
        sys.stdout = open('BAI16.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    arr = [int(x) for x in data[1:1+n]]
    
    pref_max = [-float('inf')] * n
    cur = 0
    mx = -float('inf')
    for i in range(n):
        cur = max(arr[i], cur + arr[i])
        mx = max(mx, cur)
        pref_max[i] = mx
        
    suff_max = [-float('inf')] * n
    cur = 0
    mx = -float('inf')
    for i in range(n - 1, -1, -1):
        cur = max(arr[i], cur + arr[i])
        mx = max(mx, cur)
        suff_max[i] = mx
        
    ans = -float('inf')
    for i in range(n - 1):
        ans = max(ans, pref_max[i] + suff_max[i + 1])
    print(ans)
solve()
