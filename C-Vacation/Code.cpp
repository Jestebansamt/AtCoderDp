#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<vector<ll>> v(N,vector<ll>(3)), dp(N, vector<ll>(3,-1)); 
int n;

ll f(int i, int last){
    ll &r = dp[i][last];
    if(i == n) return 0;
    if(r != -1) return r;
    r = max(f(i+1,(last+1)%3), f(i+1,(last+2)%3))+v[i][last];
    return r;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> v[i][j];
    cout << max(max(f(0,0),f(0,1)),f(0,2));
    return 0;
}