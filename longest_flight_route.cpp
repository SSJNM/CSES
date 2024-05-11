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

void dfs(vector<vector<int>>& adj,vector<int>& visited,stack<int>& st,int node){
    visited[node] = true;
    for(auto edge:adj[node]){
        if(!visited[edge]){
            dfs(adj,visited,st,edge);
        }
    }
    st.push(node);
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
    }
    vector<int> visited(n+1);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,st,i);
        }
    }
    vector<int> dist(n+1,-INT_MAX);
    vector<int> par(n+1,0);
    for(int i=0;i<=n;i++){
        par[i] = i;
    }
    dist[1] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto edge:adj[node]){
            if(dist[node] != -INT_MAX && dist[edge] < dist[node] + 1){
                dist[edge] = dist[node]+1;
                par[edge] = node; 
            }
        }
    }
    if(dist[n] == -INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]+1<<endl;
    vector<int> ans;
    ans.push_back(n);
    int x = par[n];
    ans.push_back(x);
    while(x != par[x]){
        x = par[x];
        ans.push_back(x);
    }
    reverse(ans.begin(),ans.end());
    for(auto a:ans){
        cout<<a<<" ";
    }
    return 0;
}