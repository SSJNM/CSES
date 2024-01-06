#include <bits/stdc++.h>
using namespace std;

int num_pages(vector<int>& pages,vector<int>& prices,int mp,vector<vector<int>>&dp,int price,int p){
    if(p >= pages.size()){
        return dp[price][p] = 0;
    }
    // if(price < mp && p == pages.size()-1){
    //     return 1;
    // }
    int n1,n2;
    if(dp[price+prices[p]][p+1] == -1)
    n1 = pages[p] + num_pages(pages,prices,mp,dp,price+prices[p],p+1);
    else
    n1 = pages[p] + dp[price+prices[p]][p+1];
    if(dp[price][p+1] == -1) 
    n2 = num_pages(pages,prices,mp,dp,price,p+1);
    else
    n2 = dp[price][p+1];
    if(price + prices[p] > mp){
        return n2;
    }
    return dp[price][p] = max(n1,n2);
}


int main(){
    int n,max_price;
    cin>>n>>max_price;
    vector<int> pages(n);
    vector<int> prices(n);
    vector<vector<int>> dp(100001,vector<int>(1000,-1));
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }  
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<num_pages(pages,prices,max_price,dp,0,0);   
    return 0;
}