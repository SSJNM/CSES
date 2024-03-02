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


int dp[1001][100001];
int total_pages(vector<int>& prices,vector<int>& pages,int sum){
    for(int i=0;i<prices.size();i++){
        bool flag = false;
        for(int j=0;j<=sum;j++){
            dp[i+1][j] = dp[i][j];
            if(j>= prices[i]){
                dp[i+1][j] = max(dp[i][j],pages[i]+dp[i][j-prices[i]]);
                flag = true;
            }
        }
    }
    return dp[prices.size()][sum];
}


int main(){
    fast_cin();
    int n,x;
    cin>>n>>x;
    vector<int> prices(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    memset(dp,0,sizeof(dp));
    cout<<total_pages(prices,pages,x);
    return 0;
}