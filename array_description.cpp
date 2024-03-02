#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define ln 

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    if(v[0] == 0){
        for(int i=1;i<=m;i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][v[0]]=1;
    }

    for(int i=1;i<n;i++){
        if(v[i] != 0){
            if(v[i]-1 >= 0)
            (dp[i][v[i]] += (dp[i-1][v[i]-1] % MOD)) %= MOD;
            if(v[i]+1 <= m)
            (dp[i][v[i]] += (dp[i-1][v[i]+1] % MOD)) %= MOD;
            if(v[i] <= m)
            (dp[i][v[i]] += (dp[i-1][v[i]] % MOD)) %= MOD;
        }
        else{
            for(int j=1;j<=m;j++){
                if(j-1>=0)
                (dp[i][j] += (dp[i-1][j-1] % MOD))%= MOD;
                (dp[i][j] += (dp[i-1][j] % MOD)) %= MOD;
                if(j+1<=m)
                (dp[i][j] += (dp[i-1][j+1] % MOD)) %= MOD;
            } 
        }
    }
    int ans = 0;
    // All Possiblities
    for(int i=1;i<=m;i++)
    (ans += (dp[n-1][i] % MOD)) %= MOD;
    cout<<ans;
    return 0;
}