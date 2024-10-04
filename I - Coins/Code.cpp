#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,i,k;
const int N = 3e3;
vector<vector<double>> dp(N, vector<double>(N,-1)), v(N, vector<double>(2,-1));

double f(int i, int j){
	if(i >= n) return (j <= k) ? 1 : 0;
	double &r= dp[i][j];
	if(r != -1) return r;

	r = (f(i+1,j) * v[i][0]) + ((f(i+1,j+1) * v[i][1])) ;
	return r;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	k= n/2;
	for(i = 0; i < n; ++i) cin >> v[i][0];
	for(i = 0; i < n; ++i) v[i][1] = 1 - v[i][0];
	cout << setprecision(9) << f(0,0);

	return 0;
}