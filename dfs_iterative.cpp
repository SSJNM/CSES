#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> adj,vector<bool>& visited,int node){
    stack<int> st;
    st.push(node);
    // cout<<st.top()<<endl; 
    while(!st.empty()){
        int s = st.top();
        st.pop();
        if(!visited[s]){
            cout<<s<<endl;
            visited[s] = true;
            for(int j = 0;j<adj[s].size();j++){
                st.push(adj[s][j]);
            } 
        }
    }
}

void solve(vector<vector<int>> adj,vector<bool>& visited){
    for(int i = 0;i<adj.size();i++){
        if(!visited[i]){
            dfs(adj,visited,0);
        }
    }    
}

int main(){
    vector<vector<int>> adj;
    adj.push_back({1,2,3});
    adj.push_back({0,3,4});
    adj.push_back({0,4});
    adj.push_back({1,0});
    adj.push_back({1,2});
    adj.push_back({});
    // for(int i=0;i<adj.size();i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<bool> visited(adj.size(),false);
    solve(adj,visited);
    return 0;
}