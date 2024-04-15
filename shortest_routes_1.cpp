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





void bfs(vector<vector<pair<ll,ll>>>& adj,vector<ll>& visited,vector<ll>& dist,ll src){
  	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,src});
    dist[src] = 0;
  	while(!pq.empty()){
      	ll node = pq.top().second;
      	pq.pop();
        if (visited[node]) continue;
        visited[node]=1;
        for(auto edge:adj[node]){
          if(dist[edge.first]>dist[node] + edge.second){
			      dist[edge.first] = dist[node] + edge.second;  
            pq.push({dist[edge.first],edge.first});
          }
        } 
    }
}

int main() {
  ll n,m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(ll i=0;i<m;i++){
    ll ex,ey,w;
    cin>>ex>>ey>>w;
    adj[ex].push_back({ey,w});
    // adj[ey].push_back({ex,w});
  } 
  vector<ll> visited(n+1);
  vector<ll> dist(n+1,LONG_LONG_MAX);
  bfs(adj,visited,dist,1);
  for(ll i=1;i<=n;i++){
    cout<<dist[i]<<" ";
  }
  return 0;
}
