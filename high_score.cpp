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

void bfs(ll n,vector<vector<pair<ll,ll>>>& adj,vector<ll>& dist,ll node){
  queue<ll> q;
  vector<ll> visited(n+1);
  q.push(node);
  while(!q.empty()){
    ll u = q.front();
    q.pop();
    if(u == n){
      dist[n] = -1;
    }
    for(auto edge:adj[u]){
      ll v = edge.first;
      ll w = edge.second;
      if(!visited[v]){
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

void bellmanford(ll n,vector<vector<ll>>& edges,vector<ll>& dist){
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
        }
    }
}

int main() {
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> edges(m,vector<ll>(3));
  for(ll i=0;i<m;i++){
    cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
  } 
  vector<ll> dist(n+1,LONG_LONG_MIN);
  dist[1]=0;
  // for(auto x:edges){
  //   cout<<x[0]<<x[1]<<x[2]<<endl;
  // }
  bellmanford(n,edges,dist);
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(ll i=0;i<edges.size();i++){
      ll ex=edges[i][0];
      ll ey=edges[i][1];
      ll w=edges[i][2];
      adj[ex].push_back({ey,w});
  }
  for(ll i=1;i<=n;i++){
    if(dist[i] != LONG_LONG_MIN){
      for(auto edge:adj[i]){
        ll dest = edge.first;
        ll w = edge.second;
        if(dist[i]+w> dist[dest]){
          bfs(n,adj,dist,i);       
        }
      }
    }  
  }
  cout<<dist[n];
  return 0;
}
