#include <bits/stdc++.h>
using namespace std;
// Bai 18: MangHieuXoay (Diamond update on 2D grid using Rotated array)
// Add V to |i - r| + |j - c| <= d
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI18.INP", "r")) {
        freopen("BAI18.INP", "r", stdin);
        freopen("BAI18.OUT", "w", stdout);
    }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    // coordinate transform: u = i + j, v = i - j + m
    // size of u: n + m + 2. size of v: n + m + 2
    int MAXU = n + m + 2;
    int MAXV = n + m + 2;
    vector<vector<long long>> d_arr(MAXU + 2, vector<long long>(MAXV + 2, 0));
    
    while (q--) {
        int r, c, d;
        long long v;
        cin >> r >> c >> d >> v;
        int u1 = r + c - d;
        int u2 = r + c + d;
        int v1 = r - c + m - d;
        int v2 = r - c + m + d;
        
        u1 = max(1, u1); u2 = min(MAXU, u2);
        v1 = max(1, v1); v2 = min(MAXV, v2);
        
        if (u1 <= u2 && v1 <= v2) {
            d_arr[u1][v1] += v;
            d_arr[u2+1][v1] -= v;
            d_arr[u1][v2+1] -= v;
            d_arr[u2+1][v2+1] += v;
        }
    }
    
    for (int i = 1; i <= MAXU; ++i) {
        for (int j = 1; j <= MAXV; ++j) {
            d_arr[i][j] += d_arr[i-1][j] + d_arr[i][j-1] - d_arr[i-1][j-1];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << d_arr[i+j][i-j+m] << (j == m ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
