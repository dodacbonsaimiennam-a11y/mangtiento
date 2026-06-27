#include <bits/stdc++.h>
using namespace std;
// Bai 14: Cap so cong
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI14.INP", "r")) {
        freopen("BAI14.INP", "r", stdin);
        freopen("BAI14.OUT", "w", stdout);
    }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> diff1(n + 2, 0);
    vector<long long> diff2(n + 2, 0);
    while (q--) {
        int l, r;
        long long d;
        cin >> l >> r >> d;
        diff2[l] += d;
        diff2[r + 1] -= d;
        diff1[r + 1] -= (r - l + 1) * d;
    }
    for (int i = 1; i <= n; ++i) {
        diff1[i] += diff1[i-1] + diff2[i];
    }
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff1[i];
        cout << cur << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
