#include <bits/stdc++.h>
using namespace std;
// Bai 11: Trung binh cong >= K
long long bit_arr[200005];
void update(int idx, int val, int n) {
    for (; idx <= n; idx += idx & -idx) bit_arr[idx] += val;
}
long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit_arr[idx];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI11.INP", "r")) {
        freopen("BAI11.INP", "r", stdin);
        freopen("BAI11.OUT", "w", stdout);
    }
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n + 1, 0);
    vector<long long> pref(n + 1, 0);
    vector<long long> vals;
    vals.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= k;
        pref[i] = pref[i-1] + a[i];
        vals.push_back(pref[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    long long ans = 0;
    int sz = vals.size();
    for (int i = 0; i <= n; ++i) {
        int pos = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;
        ans += query(pos);
        update(pos, 1, sz);
    }
    cout << ans << "\n";
    return 0;
}
