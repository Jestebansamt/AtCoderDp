#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int const N = 1e5 + 1;
    int n,w; cin >> n >> w;
    vector<pair<int,int>> v(n+1);
    vector<vector<ll>> dp(101, vector<ll>(N,0));

    for(int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first;
    sort(v.rbegin(),v.rend());

    for(int j = v[0].second; j <= w; ++j) dp[0][j] = v[0].first;

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < v[i].second; ++j) dp[i][j] = dp[i-1][j];

        for(int j = v[i].second; j <= w; ++j){
            dp[i][j] = max(dp[i-1][j-v[i].second] + v[i].first, dp[i-1][j]);
        }
    }
    
    cout << dp[n-1][w];

    return 0;
}