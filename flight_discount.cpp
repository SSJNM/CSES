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


void dijkstra(vector<vector<pair<ll,ll>>>& adj,vector<ll>& dist,ll src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> visited(adj.size());
    pq.push({0,src});
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u]=1;
        for(auto edge:adj[u]){
            ll v = edge.first;
            ll w = edge.second;
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                if(dist[v] != LONG_LONG_MAX)
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    fast_cin();
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<pair<ll,ll>>> adjrev(n+1);
    for(ll i=0;i<m;i++){
        ll ex,ey,w;
        cin>>ex>>ey>>w;
        adj[ex].push_back({ey,w});
        adjrev[ey].push_back({ex,w});
    }    
    vector<ll> dist(n+1,LONG_LONG_MAX);
    vector<ll> distrev(n+1,LONG_LONG_MAX);
    dist[1] = 0;
    dijkstra(adj,dist,1);
    distrev[n] = 0;
    dijkstra(adjrev,distrev,n);
    ll price=LONG_LONG_MAX;
    // for(auto x:dist){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto y:distrev){
    //     cout<<y<<" ";
    // }
    for(ll u=1;u<=n;u++){
        for(auto edge:adj[u]){
            ll v = edge.first;
            ll w = edge.second;
            if(dist[v] != LONG_LONG_MAX && distrev[v] != LONG_LONG_MAX)
            price = min(price,dist[u] + w/2 + distrev[v]); 
        }
    }
    cout<<price;
    return 0;
}