#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI2.INP", "r")) {
        freopen("BAI2.INP", "r", stdin);
        freopen("BAI2.OUT", "w", stdout);
    }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }
    long long left_sum = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (left_sum == total_sum - left_sum - a[i]) {
            ans = i;
            break;
        }
        left_sum += a[i];
    }
    if(ans != -1) ans += 1; // 1-based index 
    cout << ans << "\n";
    return 0;
}
