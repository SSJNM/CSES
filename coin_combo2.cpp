#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln 

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
using namespace std;

int dp[1000001][101];

int ways(vector<int>&coins,int sum,int idx){
    if(idx >= coins.size() || sum<0){
        return dp[sum][idx]=0;
    }
    if(sum == 0){
        return dp[sum][idx] = 1;
    }
    int w1=0;
    if(sum>=coins[idx]){
        if(dp[sum-coins[idx]][idx] == -1) 
        dp[sum-coins[idx]][idx] = ways(coins,sum-coins[idx],idx) % MOD;
        w1 = dp[sum-coins[idx]][idx] % MOD;
    }
    if(dp[sum][idx+1] == -1) 
    dp[sum][idx+1] = ways(coins,sum,idx+1) % MOD;
    int w2 = dp[sum][idx+1] % MOD;
    return dp[sum][idx] = (w1+w2)% MOD;
}

int main(){
    fast_cin();
    int n,sum;
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<ways(coins,sum,0);
    return 0;
}