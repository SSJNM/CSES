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

int c=0;

void dfs(unordered_map<int,vector<int>>& adj,vector<int>& visited,int node){
    visited[node] = 1;
    for(auto edge:adj[node]){
        if(!visited[edge]){
            dfs(adj,visited,edge);
        }
    }
}

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> adj;
    for(int i=1;i<=n;i++){
        adj[i] = vector<int>();
    }
    for(int i=0;i<m;i++){
        int ex,ey;
        cin>>ex>>ey;
        adj[ex].push_back(ey);
        adj[ey].push_back(ex);        
    }
    vector<int> visited(n+1,0);
    vector<int> ans;
    for(auto node:adj){
        if(!visited[node.first]){
            dfs(adj,visited,node.first);
            ans.push_back(node.first);
            c++;
        }
    }
    cout<<c-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    return 0;
}