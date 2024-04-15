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

bool bellmanford(ll n,vector<vector<ll>>& edges,vector<ll>& dist){
    for(ll j=1;j<n;j++){
        for(ll i=0;i<edges.size();i++){
            ll src = edges[i][0];
            ll dest = edges[i][1];
            ll w = edges[i][2];
            if(dist[src] != LONG_LONG_MIN)
            dist[dest] = max(dist[dest],dist[src]+w);
        }
    }
    for(ll i=0;i<edges.size();i++){
        ll src = edges[i][0];
        ll dest = edges[i][1];
        ll w = edges[i][2];
        if(dist[src] != LONG_LONG_MIN && dist[src]+w>dist[dest]){
          dist[dest] = max(dist[dest],dist[src]+w);
          if(dest == n) return false;
        }
    }
    return true;
}

int main() {
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> edges(m,vector<ll>(3));
  for(ll i=0;i<m;i++){
    ll ex,ey,w;
    cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
  } 
  vector<ll> dist(n+1,LONG_LONG_MIN);
  dist[1]=0;
  // for(auto x:edges){
  //   cout<<x[0]<<x[1]<<x[2]<<endl;
  // }
  if(bellmanford(n,edges,dist)){
    if(dist[n] >= INT_MAX)
    cout<<-1<<endl;
    else
    cout<<dist[n]<<" "; 
  }
  else
  cout<<-1<<endl;
  return 0;
}
