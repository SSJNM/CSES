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



void floyd(vector<vector<ll>>& dist){
  int n=dist.size()-1;
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  ll n,m,q;
  cin>>n>>m>>q;
  vector<vector<ll>> adj(n+1,vector<ll>(n+1,LONG_LONG_MAX));
  for(ll i=0;i<m;i++){
    ll ex,ey,w;
    cin>>ex>>ey>>w;
    if(adj[ex][ey] == LONG_LONG_MAX){
      adj[ex][ey] = w;
      adj[ey][ex] = w;
    }
    else{
      adj[ex][ey] = min(adj[ex][ey],w);
      adj[ey][ex] = min(adj[ey][ex],w);
    }
  } 
  for(ll i=1;i<=n;i++){
    adj[i][i] = 0;
  }
  floyd(adj);

  for(ll i=0;i<q;i++){
    ll x,y;
    cin>>x>>y;
    if(adj[x][y] == LONG_LONG_MAX) cout<<-1<<endl;
    else
    cout<<adj[x][y]<<endl;
  }
  return 0;
}
