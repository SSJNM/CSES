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
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto edge:adj[i]){
            indegree[edge]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]) q.push(i);
    }
    int count=0;
    vector<int> visited(n+1);
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        ans.push_back(node);
        for(auto edge:adj[node]){
            indegree[edge]--;
            if(!indegree[edge]){
                q.push(edge);
            }
            visited[edge] = 1;
        }
        count++;
    }
    if(count != n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}