#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int y,vector<string> & visited){
    visited[x][y] = '#';
    if(visited[x-1][y] != '#')
    dfs(x-1,y,visited);
    if(visited[x+1][y] != '#')
    dfs(x+1,y,visited);
    if(visited[x][y-1] != '#')
    dfs(x,y-1,visited);
    if(visited[x][y+1] != '#')
    dfs(x,y+1,visited);
}

void solve(int n, int m,vector<string> & visited){
    int count=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] != '#'){
                dfs(i,j,visited);
                count++;
            }
        }
    }
    cout<<count;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> visited(n+2,string(m+2,'#'));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            cin>>visited[i][j];
        }
    }
    // Print Ans
    // for(int i = 0;i<n+2;i++){
    //     for(int j = 0;j<m+2;j++){
    //         cout<<visited[i][j];
    //     }
    //     cout<<endl;
    // }
    solve(n+2,m+2,visited);
    return 0;
}