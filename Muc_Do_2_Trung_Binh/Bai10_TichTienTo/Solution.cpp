#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI10.INP", "r")) {
        freopen("BAI10.INP", "r", stdin);
        freopen("BAI10.OUT", "w", stdout);
    }
    int n, q;
    long long p;
    if (!(cin >> n >> q >> p)) return 0;
    vector<long long> pref(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pref[i] = (pref[i-1] * x) % p;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        // To compute product [l, r], we need modular inverse if we just divide.
        // But since P is prime? The problem doesn't state it's prime but let's assume Fermat's Little Theorem.
        // Wait, what if x has 0? If P is large prime like 10^9+7, we can use fastpow.
        long long num = pref[r];
        long long den = pref[l-1];
        // fast pow for inverse
        long long b = p - 2;
        long long inv = 1;
        long long base = den % p;
        while(b > 0) {
            if(b % 2 == 1) inv = (inv * base) % p;
            base = (base * base) % p;
            b /= 2;
        }
        long long ans = (num * inv) % p;
        cout << ans << "\n";
    }
    return 0;
}
