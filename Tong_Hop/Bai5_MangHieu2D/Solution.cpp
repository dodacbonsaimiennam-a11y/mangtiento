#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI5.INP", "r")) {
        freopen("BAI5.INP", "r", stdin);
        freopen("BAI5.OUT", "w", stdout);
    }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> d(n + 2, vector<long long>(m + 2, 0));
    while (q--) {
        int r1, c1, r2, c2;
        long long v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        d[r1][c1] += v;
        d[r2+1][c1] -= v;
        d[r1][c2+1] -= v;
        d[r2+1][c2+1] += v;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << d[i][j] << (j == m ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
