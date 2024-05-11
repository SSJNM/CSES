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
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        dp[i][1] = i-1;
    }

    for(int j=1;j<=m;j++){
        dp[1][j] = j-1;
    }
    int i=2,j=2;
    while(i<=n && j<=m){
        if(i<=n){
            int sz = i;
            int t = sz;
            while(t<=m){
                for(int k=1;k<=sz;k++){
                    dp[i][t+k] = 1+dp[i][t-sz+k];
                }
                t += sz;
            }
        }
        if(j<=m){
            int sz = j;
            int t = sz;
            while(t<=n){
                for(int k=1;k<=sz;k++){
                    dp[t+k][j] = 1+dp[t-sz+k][j];
                }
                t += sz;
            }
        }
        i++;
        j++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<dp[n][m];
    return 0;
}