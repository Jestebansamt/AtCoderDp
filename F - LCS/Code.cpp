#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n,m,i,j,k;
	string s1, s2; cin >> s1 >> s2;
	n = s1.size(); m = s2.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1,0));

	for(i = 1; i <= n; ++i){
		for(j = 1; j <= m ;++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string ans = "";
	i = n; j = m;
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
			ans+= s1[i-1];
			j--, i--;
		}else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}