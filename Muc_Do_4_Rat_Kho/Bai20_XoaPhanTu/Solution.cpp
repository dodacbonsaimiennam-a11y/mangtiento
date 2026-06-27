#include <bits/stdc++.h>
using namespace std;
// Bai 20: XoaPhanTu (LeetCode 1664: Ways to Make a Fair Array)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI20.INP", "r")) {
        freopen("BAI20.INP", "r", stdin);
        freopen("BAI20.OUT", "w", stdout);
    }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    long long even_total = 0, odd_total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) even_total += a[i];
        else odd_total += a[i];
    }
    
    long long even_left = 0, odd_left = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long even_right = even_total - even_left - (i % 2 == 0 ? a[i] : 0);
        long long odd_right = odd_total - odd_left - (i % 2 != 0 ? a[i] : 0);
        
        if (even_left + odd_right == odd_left + even_right) {
            ans++;
        }
        
        if (i % 2 == 0) even_left += a[i];
        else odd_left += a[i];
    }
    cout << ans << "\n";
    return 0;
}
