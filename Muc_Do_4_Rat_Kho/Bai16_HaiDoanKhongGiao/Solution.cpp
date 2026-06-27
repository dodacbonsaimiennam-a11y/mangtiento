#include <bits/stdc++.h>
using namespace std;
// Bai 16: HaiDoanKhongGiao (Max sum of 2 non-overlapping subarrays)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI16.INP", "r")) {
        freopen("BAI16.INP", "r", stdin);
        freopen("BAI16.OUT", "w", stdout);
    }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<long long> pref_max(n, -1e18);
    long long cur = 0, mx = -1e18;
    for (int i = 0; i < n; ++i) {
        cur = max(a[i], cur + a[i]);
        mx = max(mx, cur);
        pref_max[i] = mx;
    }
    
    vector<long long> suff_max(n, -1e18);
    cur = 0; mx = -1e18;
    for (int i = n - 1; i >= 0; --i) {
        cur = max(a[i], cur + a[i]);
        mx = max(mx, cur);
        suff_max[i] = mx;
    }
    
    long long ans = -1e18;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, pref_max[i] + suff_max[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}
