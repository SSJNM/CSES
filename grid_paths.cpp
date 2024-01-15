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
    int n;
    cin>>n;
    char grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    ll ans[n][n];
    memset(ans,0,sizeof(ans));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout<<0<<endl;
    }
    else{
        ans[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '*'){
                    ans[i][j] = 0;
                }
                else{
                    if(j-1 >= 0){
                        ans[i][j] += ans[i][j-1];
                    }
                    if(i-1 >=0){
                        ans[i][j] += ans[i-1][j];
                    }
                }
                ans[i][j] =  ans[i][j] % MOD;
                // cout<<ans[i][j]<<" ";
            }
            // cout<<endl;
        }

        cout<<ans[n-1][n-1];
    }
    return 0;
}