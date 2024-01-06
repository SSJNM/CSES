#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1000001];
const int MOD = (int)1e9 + 7; 

int minicoin(vector<int> coins,int sum){
    if(sum < 0){
        return MOD;
    }
    if(sum == 0){
        return dp[sum] = 0;
    }
    ll a1 = MOD;
    for(auto x:coins){
        if(sum-x>=0){
            if(dp[sum-x] == -1){
                dp[sum-x] = minicoin(coins,sum-x);
            }   
            a1 = min(1 + dp[sum-x],a1);
        }
    }
    return dp[sum] = a1;
}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = minicoin(coins,sum);
    dp[sum] == MOD ?cout<<-1:cout<<dp[sum];
    return 0;
}