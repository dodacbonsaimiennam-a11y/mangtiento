#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI4.INP", "r")) {
        freopen("BAI4.INP", "r", stdin);
        freopen("BAI4.OUT", "w", stdout);
    }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> d(n + 2, 0);
    while (q--) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r+1] -= v;
    }
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += d[i];
        cout << cur << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
