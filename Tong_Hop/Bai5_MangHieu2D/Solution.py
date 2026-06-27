import sys

def solve():
    # TODO: Implement solution here
    pass

if __name__ == '__main__':
    # Đọc ghi file theo chuẩn thi đấu
    try:
        sys.stdin = open('BAI5.INP', 'r')
        sys.stdout = open('BAI5.OUT', 'w')
    except FileNotFoundError:
        pass
        
    solve()
