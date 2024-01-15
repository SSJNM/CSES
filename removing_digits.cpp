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

// string digits(int n){
    // string str1;
    // return (n>0 ? (digits(n/10) + str1.push_back('0'+ n%10)) : str1);
// }

int dp[1000001];

int steps(int n){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return dp[n] = 0;
    }
    string dg = to_string(n);
    int mini = INT_MAX;
    for(int i=0;i<dg.size();i++){
        int d = dg[i]-'0';
        // cout<<n<<" "<<d<<endl;
        if(dg[i] != '0' && d>0){
            if(dp[n-d] == -1)
            dp[n-d] = steps(n-d);
            mini = min(mini,1 + dp[n-d]);
        }
    }
    return dp[n] = mini;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<steps(n);
    return 0;
}   