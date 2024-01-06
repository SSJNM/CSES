#include<bits/stdc++.h>
using namespace std;


pair<int,int> A;
pair<int,int> B;
int finaldist=0;
string finalpath;

vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};

bool check(vector<string>& grid,int x,int y){
    return x>=0 && y>=0 && x<grid.size() && x<grid[0].size();
}
void bfs(queue<pair<int,int>> q,vector<string> & grid,int dist,string path){
    int x=q.front().first;
    int y=q.front().second;
    grid[x][y] = '#';
    for(auto d:dir){
        if(check(grid,x+d.first,y+d.second) && grid[x+d.first][y+d.second] == '.'){
            q.push({x+d.first,y+d.second});
        }
    }
    q.pop();
    bfs(q,grid,dist+1,path);
}

void solve(int n, int m,vector<string> & grid){
    string path;
    int dist=0;
    queue<pair<int,int>> q;
    q.push(A);
    bfs(q,grid,dist,path);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n,string(m,'#'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                A.first = i;
                A.second = j;
            }
            if(grid[i][j] == 'B'){
                B.first = i;
                B.second = j;
            }
        }
    }
    solve(n,m,grid);
    return 0;
}