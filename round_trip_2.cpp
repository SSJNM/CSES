#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define ln 

#define mp make_pair
#define pb push_back
#define fi first
#define pii pair<int,int> 
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int br=-1;

void dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& onstack,stack<int>& st,int par,int node){
    if(br != -1) return; 
    visited[node] = true;
    st.push(node);
    onstack[node] = true;
    for(auto edge:adj[node]){
        if(br != -1) return;
        int dest = edge;
        if(onstack[dest] && visited[dest] && par != node){
            br = dest;
            return ;
        }
        if(!visited[dest]){
            dfs(adj,visited,onstack,st,node,dest);
        }
    }
    if(br!=-1) return ;
    st.pop();
    onstack[node] = false;
}

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int ex,ey;
        cin>>ex>>ey;
        adj[ex].pb(ey);
    }
    // for(int i=1;i<=n;i++){
    //     for(auto x:adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    // return 0;
    stack<int> st;
    vector<int> visited(n+1);
    vector<int> onstack(n+1);
    for(int i=1;i<=n;i++){
        if(!visited[i])
        dfs(adj,visited,onstack,st,-1,i);
    }
    if(br == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(br);
    int x = st.top();
    while(st.size()>0 && x != br){
        x = st.top();
        ans.push_back(x);
        if(!st.empty())
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto a:ans){
        cout<<a<<" ";
    }
    return 0;
} 