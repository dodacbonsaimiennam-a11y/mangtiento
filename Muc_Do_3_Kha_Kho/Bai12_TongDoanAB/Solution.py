import sys
from collections import deque
def solve():
    try:
        sys.stdin = open('BAI12.INP', 'r')
        sys.stdout = open('BAI12.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    a = int(data[1])
    b = int(data[2])
    arr = [0] + [int(x) for x in data[3:3+n]]
    
    dp = [-float('inf')] * (n + 1)
    dp[1] = arr[1]
    dq = deque()
    
    for i in range(2, n + 1):
        r = i - a
        l = i - b
        if r >= 1:
            while dq and dp[dq[-1]] <= dp[r]:
                dq.pop()
            dq.append(r)
        while dq and dq[0] < l:
            dq.popleft()
        if dq:
            dp[i] = dp[dq[0]] + arr[i]
            
    print(dp[n])
solve()
