#include <bits/stdc++.h>
using namespace std;
// Bai 13: Dem doan con nho hon K (Subarray sum < K)
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
    if (fopen("BAI13.INP", "r")) {
        freopen("BAI13.INP", "r", stdin);
        freopen("BAI13.OUT", "w", stdout);
    }
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> pref(n + 1, 0);
    vector<long long> vals;
    vals.push_back(0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pref[i] = pref[i-1] + x;
        vals.push_back(pref[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    long long ans = 0;
    int sz = vals.size();
    for (int i = 0; i <= n; ++i) {
        // We need pref[i] - pref[j] < K => pref[j] > pref[i] - K
        long long target = pref[i] - k;
        int pos = upper_bound(vals.begin(), vals.end(), target) - vals.begin();
        // we want count of elements > target. Which means from pos+1 to sz.
        // so total_elements_inserted - query(pos)
        ans += i - query(pos);
        
        int insert_pos = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;
        update(insert_pos, 1, sz);
    }
    cout << ans << "\n";
    return 0;
}
