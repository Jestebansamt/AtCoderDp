#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+1;
vector<vector<int>> v(N);
vector<int> dp(N,-1);
int n, m; 

int f(int i){
	if(v[i].empty()) return 0;
	if(dp[i] != -1) return dp[i];
	for(auto&a:v[i]){
		dp[i] = max(dp[i], f(a)+1);
	}
	return dp[i];
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<int> mask(n+1,0);
	
	for(int i = 0; i < m; ++i){
		int a,b; cin >> a >> b;
		v[a].push_back(b);
		mask[b] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(!mask[i]){
			ans = max(ans,f(i));
		}
	}
	
	cout << ans << " ";


	return 0;
}