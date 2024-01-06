#include <bits/stdc++.h>
using namespace std;

long long dp[1000002];
const long long MOD = 1e9+7;

long long ways(vector<long long>& moves,long long sum){
    if (sum<0){
        return 0;
    }
    if (sum == 0){
        return 1;
    }

    if(dp[sum] != -1)
        return dp[sum];

    long long total = 0;

    for(unsigned long long i=0;i<moves.size();i++){
        total += ways(moves ,sum-moves[i]);         
    }
    
    return dp[sum] = total % MOD;
}

int main(){

    memset(dp, -1, sizeof(dp));
    long long sum;
    cin>> sum;
    vector<long long> moves = {1,2,3,4,5,6};
    cout<<ways(moves, sum)<<endl;
    return 0;
}   