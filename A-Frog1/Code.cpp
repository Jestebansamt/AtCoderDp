#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<ll> dp(N,-1), v(N,0);
int n;
ll f(int i){
    if(i == n-1) return 0;
    if(i > n-1) return N;
    if(dp[i] != -1) return dp[i];
    dp[i] = min(abs(v[i]-v[i+1]) + f(i+1),abs(v[i]-v[i+2]) + f(i+2));
    return dp[i];   
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << f(0);

    return 0;
}