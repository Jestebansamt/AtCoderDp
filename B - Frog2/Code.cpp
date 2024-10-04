#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<ll> dp(N,-1), v(N,0);
int n,k;
ll f(int i){
    if(i == n-1) return 0;
    if(i > n-1) return N;
    if(dp[i] != -1) return dp[i];
    dp[i] = abs(v[i]-v[i+1]) + f(i+1);
    for(int j = 2; j <= k; ++j){
        dp[i] = min(dp[i], abs(v[i]-v[i+j]) + f(i+j));
    }
    return dp[i];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << f(0);

    return 0;
}