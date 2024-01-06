#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1000001];
const int MOD = (int)1e9 + 7; 


int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    for(int i=0;i<=sum;i++){
        dp[i] = INT_MAX;
    }
    // memset(dp,MOD,sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(j-coins[i]>=0){
                dp[j] = min(1 + dp[j-coins[i]],dp[j]);
            }      
        }
    }
    cout<<(dp[sum] == INT_MAX ?-1:dp[sum]);
    return 0;
}