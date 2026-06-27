import sys
def solve():
    try:
        sys.stdin = open('BAI11.INP', 'r')
        sys.stdout = open('BAI11.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    k = int(data[1])
    arr = [int(x) - k for x in data[2:2+n]]
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i+1] = pref[i] + arr[i]
    
    vals = sorted(list(set(pref)))
    def bisect_lower(arr, val):
        l, r = 0, len(arr) - 1
        while l <= r:
            m = (l + r) // 2
            if arr[m] < val: l = m + 1
            else: r = m - 1
        return l
    
    bit = [0] * (len(vals) + 1)
    def update(idx, val):
        while idx < len(bit):
            bit[idx] += val
            idx += idx & (-idx)
            
    def query(idx):
        s = 0
        while idx > 0:
            s += bit[idx]
            idx -= idx & (-idx)
        return s
        
    ans = 0
    for i in range(n + 1):
        pos = bisect_lower(vals, pref[i]) + 1
        ans += query(pos)
        update(pos, 1)
    print(ans)
solve()
