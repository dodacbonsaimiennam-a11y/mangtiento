#include <bits/stdc++.h>
using namespace std;
// Bai 17: Dem hinh chu nhat co tong K
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI17.INP", "r")) {
        freopen("BAI17.INP", "r", stdin);
        freopen("BAI17.OUT", "w", stdout);
    }
    int n, m;
    long long target;
    if (!(cin >> n >> m >> target)) return 0;
    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
        }
    }
    
    long long ans = 0;
    for (int c1 = 1; c1 <= m; ++c1) {
        for (int c2 = c1; c2 <= m; ++c2) {
            map<long long, int> cnt;
            cnt[0] = 1;
            long long cur = 0;
            for (int r = 1; r <= n; ++r) {
                cur += a[r][c2] - a[r][c1-1];
                if (cnt.count(cur - target)) {
                    ans += cnt[cur - target];
                }
                cnt[cur]++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
