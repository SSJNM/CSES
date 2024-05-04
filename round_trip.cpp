#include <bits/stdc++.h>
using namespace std;
 
 
int cn = -1;
 
void dfs(vector<vector<int>>& adj,vector<int>& visited,stack<int>& st,int parent,int node){
  visited[node] = 1;
  st.push(node);
  if(cn!=-1) return;
  for(auto edge:adj[node]){
    if(cn!=-1) return ;
    if(visited[edge] && edge != parent){
      cn = edge;
      return ;
    }
    else if(!visited[edge]){
		dfs(adj,visited,st,node,edge);
    }
  }
  if(cn==-1) st.pop();
}
 
int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  for(int i=0;i<m;i++){
   	int ex,ey;
    cin>>ex>>ey;
    adj[ex].push_back(ey);
    adj[ey].push_back(ex);   
  }
  vector<int> visited(n+1,0);
  stack<int> st;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      dfs(adj,visited,st,-1,i);
      if(cn != -1) break;
    }
  }
  if(cn == -1){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  vector<int> ans;
  ans.push_back(cn);
  while(st.size()>0 && st.top() != cn){
    ans.push_back(st.top());
    st.pop();
  }
  ans.push_back(st.top());
  cout<<ans.size()<<endl;
  for(int i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
  return 0;
}
