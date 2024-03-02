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

int calculate(vector<int>& v,vector<vector<int>>&dp,int sum){
    dp[0][0] = 1;
    long long w1=0,w2=0;
    for(int i=1;i<v.size();i++){
        for(int j=0;j<=sum;j++){
            (dp[i][j] += dp[i-1][j]) %= MOD;
            if(j-v[i-1] >= 0){
                (dp[i][j] += dp[i-1][j-v[i-1]]) %= MOD;
            }
        }
    }
    return dp[v.size()-1][sum] % MOD; 
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector<int> v(n);
    long long sum = 0;
    sum = n*(n+1)/2%MOD;
    for(int i=1;i<=n;i++){
        v[i-1] = i;
    }
    if(sum%2 != 0){
        cout<<0<<endl;
        return 0;
    }
    sum = sum/2;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    int ans = calculate(v,dp,sum);
    cout<<ans<<endl;
    return 0;
}