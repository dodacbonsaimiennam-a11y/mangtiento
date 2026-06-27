#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI7.INP", "r")) {
        freopen("BAI7.INP", "r", stdin);
        freopen("BAI7.OUT", "w", stdout);
    }
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    long long cur = 0, ans = 0;
    map<long long, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        cur = ((cur + x) % k + k) % k;
        if (cnt.count(cur)) {
            ans += cnt[cur];
        }
        cnt[cur]++;
    }
    cout << ans << "\n";
    return 0;
}
