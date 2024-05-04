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
 
int bellmanford(ll n,vector<vector<ll>>& edges,vector<ll>& dist,vector<ll>& p){
    ll x;
    for(ll j=1;j<=n;j++){
        x = 0;
        for(ll i=0;i<edges.size();i++){
            ll src = edges[i][0];
            ll dest = edges[i][1];
            ll w = edges[i][2];
            if(dist[src] != LONG_LONG_MAX && dist[src]+w<dist[dest]){
              dist[dest] = dist[src]+w;
              p[dest] = src;
              x = dest;
            }
        }
    }
    // for(ll i=0;i<edges.size();i++){
    //     ll src = edges[i][0];
    //     ll dest = edges[i][1];
    //     ll w = edges[i][2];
    //     if(dist[src] != LONG_LONG_MAX && dist[src]+w<dist[dest]){
    //       ans.push_back(src);
    //       dist[dest] = dist[src]+w;
    //       p[dest] = src;
    //     }
    // }
    return x;
}
 
int  main() {
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> edges(m,vector<ll>(3));
  for(ll i=0;i<m;i++){
    cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
  } 
  vector<ll> dist(n+1,INT_MAX);
  dist[1]=0;
  vector<ll> p(n+1);
  ll x = bellmanford(n,edges,dist,p);
  // cout<<x<<endl;
  // return 0;
  if(x == 0){
    cout<<"NO"<<endl;
    return 0;
  } 
  for(int i=1;i<=n;i++){
    x = p[x];
  }
  vector<ll> path;
  ll dest = x;
  path.push_back(x);
  x = p[x];
  while(x != dest){
    path.push_back(x);
    x = p[x];
  }
  path.push_back(x);
  // for(int v = x;; v = p[v]){
  //     path.push_back(v);
  //     if(v == x && (int) path.size() > 1)
  //         break;
  // }
  reverse(path.begin(),path.end());
  cout<<"YES"<<endl;
  for(auto x:path){
    cout<<x<<" ";
  }
  return 0;
}