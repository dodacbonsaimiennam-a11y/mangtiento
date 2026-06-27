import sys
def solve():
    try:
        sys.stdin = open('BAI14.INP', 'r')
        sys.stdout = open('BAI14.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    q = int(data[1])
    idx = 2
    diff1 = [0] * (n + 2)
    diff2 = [0] * (n + 2)
    for _ in range(q):
        l = int(data[idx])
        r = int(data[idx+1])
        d = int(data[idx+2])
        idx += 3
        diff2[l] += d
        diff2[r+1] -= d
        diff1[r+1] -= (r - l + 1) * d
        
    for i in range(1, n + 1):
        diff1[i] += diff1[i-1] + diff2[i]
        
    cur = 0
    ans = []
    for i in range(1, n + 1):
        cur += diff1[i]
        ans.append(str(cur))
    print(' '.join(ans))
solve()
