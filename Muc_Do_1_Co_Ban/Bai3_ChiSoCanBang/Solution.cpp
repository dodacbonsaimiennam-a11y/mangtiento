#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI3.INP", "r")) {
        freopen("BAI3.INP", "r", stdin);
        freopen("BAI3.OUT", "w", stdout);
    }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> prefXor(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        prefXor[i] = prefXor[i-1] ^ x;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (prefXor[r] ^ prefXor[l-1]) << "\n";
    }
    return 0;
}
