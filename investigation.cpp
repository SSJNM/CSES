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
#define pll pair<ll,ll>  
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast_cin();
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll ex,ey,w;
        cin>>ex>>ey>>w;
        adj[ex].push_back({ey,w});
    }
    vector<ll> dist(n+1,LLONG_MAX);
    // dijkstra
    ll src = 1;
    dist[src] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,src});
    vector<ll> visited(n+1);
    vector<ll> num(n+1);
    vector<ll> fmini(n+1);
    vector<ll> fmaxi(n+1);
    num[1] = 1;
    fmini[1] = 0;
    fmaxi[1] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop(); 
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto node:adj[u]){
            ll v = node.first;
            ll c = node.second;
            if(dist[v] == dist[u]+c){
                num[v] = (num[v] + num[u]) % MOD;
                fmini[v] = min(fmini[v],fmini[u] + 1); 
                fmaxi[v] = max(fmaxi[v],fmaxi[u] + 1);
            }
            if(dist[v]>d+c){
                num[v] = num[u];
                fmini[v] = fmini[u] + 1;
                fmaxi[v] = fmaxi[u] + 1;
                dist[v] = (dist[u] + c);
                pq.push({dist[v],v});
            }
        }
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    cout<<dist[n]<<" "<<num[n]<<" "<<fmini[n]<<" "<<fmaxi[n]<<endl;
    return 0;
}