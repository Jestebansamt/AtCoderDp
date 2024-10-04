#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 +10, M = 1e9+7 ;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(auto&a:v) cin >> a;

    vector<vector<int>> prfx(410, vector<int>(N,0));
    for(int i=0;i<=v[0];++i) prfx[0][i]= 1; 
    for(int i=0;i<=n;++i) prfx[i][0]=1; 

    for(int i =1;i < n; ++i){
        for(int j=1; j <=k; ++j){
            prfx[i][j] = (prfx[i-1][j] + prfx[i][j-1]) % M;
            if(j-v[i]-1>= 0 ) prfx[i][j] = (prfx[i][j] - prfx[i-1][j-v[i]-1] + M) % M;
        }
    }

    cout << prfx[n-1][k];

    return 0;
}
