#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3, MOD = 1e9 +7;
vector<vector<int>> dp(N, vector<int>(N,0));
int n,m; 
vector<string> grid(N);

int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(auto&a:grid) cin >> a; 

	for(int i = 0; i < n; ++i){
		if(grid[i][0] == '#') break;
		dp[i][0] = 1;
	}
	for(int i = 0; i < m; ++i){
		if(grid[0][i] == '#') break;
		dp[0][i] = 1;
	}

	for(int i = 1 ; i < n; ++i){
		for(int j = 1; j < m; ++j){
			if(grid[i-1][j] != '#')
				dp[i][j]+= dp[i-1][j]%MOD; 
                
			if(grid[i][j-1] != '#')
				dp[i][j] += dp[i][j-1]%MOD;
			dp[i][j] %= MOD;
		}
	}

	cout << dp[n-1][m-1];

	return 0;
}

