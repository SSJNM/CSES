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

int dp[501][501];

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    // memset(dp,INT_MAX,sizeof(dp));    
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i=1;i<=n;i++){
        dp[i][1] = i-1;
    }

    for(int j=1;j<=m;j++){
        dp[1][j] = j-1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i==j) dp[i][j] = 0;
            else{
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j],1 + dp[i-k][j] + dp[k][j]);
                } 
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j],1 + dp[i][j-k] + dp[i][k]);
                } 
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][m];
    return 0;
}