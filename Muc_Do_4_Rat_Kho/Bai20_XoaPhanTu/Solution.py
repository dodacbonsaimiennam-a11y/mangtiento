import sys
def solve():
    try:
        sys.stdin = open('BAI20.INP', 'r')
        sys.stdout = open('BAI20.OUT', 'w')
    except:
        pass
    data = sys.stdin.read().split()
    if not data: return
    n = int(data[0])
    arr = [int(x) for x in data[1:1+n]]
    
    even_tot = sum(arr[i] for i in range(0, n, 2))
    odd_tot = sum(arr[i] for i in range(1, n, 2))
    
    ans = 0
    even_left = odd_left = 0
    for i in range(n):
        if i % 2 == 0:
            even_right = even_tot - even_left - arr[i]
            odd_right = odd_tot - odd_left
        else:
            even_right = even_tot - even_left
            odd_right = odd_tot - odd_left - arr[i]
            
        if even_left + odd_right == odd_left + even_right:
            ans += 1
            
        if i % 2 == 0: even_left += arr[i]
        else: odd_left += arr[i]
        
    print(ans)
solve()
