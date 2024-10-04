#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// v.first -> Weight, v.second -> Value

	ll n, w; cin >> n >> w;
	const ll N = 1e5 +1, V = INT_MAX;
	vector<vector<ll>> dp(n+1,vector<ll> (N,V));
	vector<pair<ll,ll>> v(n);

	for(auto&[a,b]: v) cin >> a >> b;
	sort(v.begin(), v.end());

	dp[0][v[0].second] = v[0].first;

	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= N; ++j){
            dp[i][j] = dp[i-1][j]; 
			if(dp[i][j] >= v[i].first){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i].second] + v[i].first);
			}
		}
	}

	ll ans = 0;
	for(ll i = 0; i < N; ++i){
		if(dp[n-1][i] != V && dp[n-1][i] <= w){
			ans = max(ans,i);
		}
	}
	cout << ans << " ";


	return 0;
}