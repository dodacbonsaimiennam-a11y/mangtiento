#include <bits/stdc++.h>
using namespace std;
// Bai 12: TongDoanAB (Frog jump A, B) DP prefix
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI12.INP", "r")) {
        freopen("BAI12.INP", "r", stdin);
        freopen("BAI12.OUT", "w", stdout);
    }
    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;
    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    // dp[i] = max(dp[j]) + arr[i] for i-b <= j <= i-a
    // We can use a deque or multiset. Deque is O(N).
    vector<long long> dp(n + 1, -1e18);
    dp[1] = arr[1];
    deque<int> dq;
    
    for(int i = 2; i <= n; i++) {
        int r = i - a;
        int l = i - b;
        if(r >= 1) {
            while(!dq.empty() && dp[dq.back()] <= dp[r]) dq.pop_back();
            dq.push_back(r);
        }
        while(!dq.empty() && dq.front() < l) dq.pop_front();
        
        if(!dq.empty()) {
            dp[i] = dp[dq.front()] + arr[i];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
