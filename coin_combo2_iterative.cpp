#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int MOD = 1e9 + 7;

int main(){
    ll n,sum;
    cin>>n>>sum;
    vector<int> coins(n);    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<ll> dp(sum+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(j-coins[i]>=0)
            dp[j] += dp[j-coins[i]] % MOD;
        }
    }
    cout<<dp[sum]%MOD<<endl;
    return 0;
}