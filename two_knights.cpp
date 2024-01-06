#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int ncr(int n,int r){
    if(n == 0 || r == 0){
        return 1;
    }
    return n * ncr(n-1,r-1)/r;
}

bool check(vector<vector<int>>& visited,int x,int y){
    return x>=0 && y>=0 && x<visited.size() && y<visited[0].size();
}

vector<vector<int>> moves={{2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
void dfs(vector<vector<int>>& visited,int i,int j,int prev){
    visited[i][j] = 1;
    if(prev != -1){
        cnt++;
    }
    for(auto mv:moves){
        if(check(visited,i+mv[0],j+mv[1]) && !visited[i+mv[0]][j+mv[1]]){
            dfs(visited,i+mv[0],j+mv[1],visited[i][j]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(!matrix[i][j]){
                dfs(matrix,i,j,-1);
            }
        }
    }
    cout<<ncr(n*n,2)-cnt<<endl;
    return 0;
}