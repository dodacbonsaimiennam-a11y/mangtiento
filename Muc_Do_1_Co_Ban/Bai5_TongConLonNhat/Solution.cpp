#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI5.INP", "r")) {
        freopen("BAI5.INP", "r", stdin);
        freopen("BAI5.OUT", "w", stdout);
    }
    int n;
    if (!(cin >> n)) return 0;
    long long max_sum = -1e18;
    long long cur_sum = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        cur_sum = max(x, cur_sum + x);
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum << "\n";
    return 0;
}
