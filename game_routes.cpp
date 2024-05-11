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
    vector<int> dp(n+1,0);
    dp[1] = 1;
    while(!st.empty() && st.top() != 1){
        st.pop();
    }

    while(!st.empty() && st.top() != n){
        int node = st.top();
        st.pop();
        for(auto edge:adj[node]){
            dp[edge] = ((ll)dp[edge] + (ll)dp[node]) % MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}