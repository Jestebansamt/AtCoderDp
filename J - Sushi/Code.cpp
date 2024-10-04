#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e2 + 10;
int c[4];
double dp[N][N][N];
int vis[N][N][N];
int n;

double f(int c1, int c2, int c3){
	if(c1 == 0 && c2 == 0 && c3 == 0) return 0.;
	double &r = dp[c1][c2][c3]; int &v = vis[c1][c2][c3];
	if(v) return r;
	v = 1; r = 1;
	if(c1 > 0) r += 1. * c1 / n * f(c1-1, c2, c3);
	
	if(c2 > 0) r += 1. * c2 / n * f(c1+1, c2-1, c3);
	
	if(c3 > 0) r += 1. * c3 / n * f(c1, c2+1, c3-1);
	
	double p0 = 1. * (n-c3-c2-c1)/ n;
	r /= 1. - p0;
	return r;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("i.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
		
	for(int i = 0 ; i < n; ++i){
		int a; cin >> a;
		c[a]++;
	}
	cout << setprecision(10) << f(c[1],c[2],c[3]);

	return 0;
}