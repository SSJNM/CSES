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

int const n=1e6+1;
int dp[n][2];

void solve(int n){
    dp[1][0] = dp[1][1]= 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = (2*(ll)dp[i-1][0] + (ll)dp[i-1][1]) % MOD;
        dp[i][1] = ((ll)dp[i-1][0] + 4*(ll)dp[i-1][1]) % MOD;
    }
}

int main(){
    fast_cin();
    int t;
    cin>>t;
    memset(dp,0,sizeof(dp));   
    solve(n);
    for(int i=0;i<t;i++){
        int n1;
        cin>>n1;
        cout<<((ll)dp[n1][0]+(ll)dp[n1][1]) % MOD;
        cout<<endl;
    }
    return 0;
}