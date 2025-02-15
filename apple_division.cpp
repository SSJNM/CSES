#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

pair<ll,ll> solve(vector<ll>& v,int i,ll w1,ll w2){
   if(i>=v.size()){
       return {w1,w2};
   }
   pair<ll,ll> c1 = solve(v,i+1,w1+v[i],w2);
   pair<ll,ll> c2 = solve(v,i+1,w1,w2+v[i]);
   return abs(c1.second - c1.first) > abs(c2.second - c2.first)  ? c2 : c1;
}

int main(){
    fast_cin();
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        v.push_back(num);
    }
    if(n == 1) cout<<v[0]<<endl;
    else if(n == 2){
        cout<<abs(v[1]-v[0])<<endl;
    }
    else{
        pair<ll,ll> p =solve(v,0,0,0);
        cout<<abs(p.second - p.first)<<endl;
    }
    return 0;
}