#include <bits/stdc++.h>
using namespace std;
// Bai 15: Tong khoang cach (Manhattan 1D)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI15.INP", "r")) {
        freopen("BAI15.INP", "r", stdin);
        freopen("BAI15.OUT", "w", stdout);
    }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * (2LL * i - n + 1);
    }
    cout << ans << "\n";
    return 0;
}
