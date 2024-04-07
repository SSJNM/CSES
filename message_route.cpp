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

int dist=1;

void bfs(queue<int>& q,vector<vector<int>>& adj,vector<int>& visited,vector<int>& parent_array,int n){
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int node = q.front();
            visited[node]=1;
            if(node == n) return;
            q.pop();
            for(auto edge:adj[node]){
                if(!visited[edge]){
                    q.push(edge);
                    parent_array[edge] = node;
                    visited[edge] = 1;
                }
            }
        }
        dist++;
    }
}

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int ex,ey;
        cin>>ex>>ey;
        adj[ex].push_back(ey);
        adj[ey].push_back(ex);
    }
    vector<int> visited(n+1,0);
    vector<int> parent_array(n+1,-1);
    // 0th case automatically handled
    for(int i=1;i<=n;i++){
        parent_array[i] = i;
    }
    // Jiska koi nhi hota woh khud hi hota hai apna, Woh akela nhi hai
    queue<int> q;
    q.push(1);
    bfs(q,adj,visited,parent_array,n);
    if(q.empty()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path(dist);
    int i = dist-1;
    path[i--] = n;

    int p = parent_array[n];
    while(p != 1){
        path[i--] = p;
        p = parent_array[p];
    }
    path[i] = 1;
    cout<<dist<<endl;
    for(auto x:path){
        cout<<x<<" ";
    }
    return 0;
}