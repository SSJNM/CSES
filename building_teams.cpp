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

bool isPossible = true; 

void dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& teams,int node,int team){
    visited[node] = 1;
    teams[node] = team;
    for(auto edge:adj[node]){
        if(visited[edge] && teams[edge] == team){
            isPossible = false;
            return ;
        }
        if(!visited[edge]){
            dfs(adj,visited,teams,edge,!team);
        }
    }
}

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int ex,ey;
        cin>>ex>>ey;
        adj[ex].push_back(ey);
        adj[ey].push_back(ex);
    }
    vector<int> visited(n+1);
    vector<int> teams(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,visited,teams,i,0);
        }
    }
    if(!isPossible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!teams[i])
        cout<<1<<" ";
        else
        cout<<2<<" ";
    }
    return 0;
}