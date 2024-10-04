#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,i;
vector<ll> v(410,0), prfx(410,0);
vector<vector<ll>> dp(410, vector<ll>(410, LONG_LONG_MAX));

ll f(int l, int r){
    if(l==r) return 0;

    if(dp[l][r] != LONG_LONG_MAX ) return dp[l][r];
    
    for(int j=l;j<r;++j){
        dp[l][r] = min(dp[l][r], f(l,j) + f(j+1,r) + prfx[r] - prfx[l-1]);
    } 
    return dp[l][r];
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(i=1;i<=n;++i){
        cin>>v[i];
        prfx[i]=v[i]+prfx[i-1];
    }
    cout << f(1,n);

    return 0;
}