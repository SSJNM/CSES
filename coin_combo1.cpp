#include <bits/stdc++.h>
using namespace std;

#define long long ll 


int ways(vector<int>& coins,int sum){
    if(sum < 0){
        return -1;
    }
    if(sum == 0){
        return 1;
    }
    int total=0;
    for(auto c1:coins){
        if(sum>=c1){
            total += ways(coins,sum-c1);
        }
    }
    return total;
}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> coins(n);    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<ways(coins,sum);
    return 0;
}