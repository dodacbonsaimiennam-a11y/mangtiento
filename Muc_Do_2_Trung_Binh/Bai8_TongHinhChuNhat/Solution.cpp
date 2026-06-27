#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI8.INP", "r")) {
        freopen("BAI8.INP", "r", stdin);
        freopen("BAI8.OUT", "w", stdout);
    }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x;
            cin >> x;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + x;
        }
    }
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        long long ans = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        cout << ans << "\n";
    }
    return 0;
}
