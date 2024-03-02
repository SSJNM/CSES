#include<bits/stdc++.h>
using namespace std;


pair<int,int> A;
pair<int,int> B;
int finaldist=0;
string finalpath;

vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};

bool check(vector<string>& grid,int x,int y){
    return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
}
void bfs(vector<string>& grid,vector<vector<pair<int,int>>>& grid_path,queue<pair<int,int>>& q,int dist){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        if(x == B.first && y == B.second) break;
        grid[x][y] = '#';
        dist++;
        int sz = q.size();
        for(int i=0;i<sz;i++){
            for(auto d:dir){
                if(check(grid,x+d.first,y+d.second) && grid[x+d.first][y+d.second] != '#'){
                    q.push({x+d.first,y+d.second});
                    grid_path[x+d.first][y+d.second] = {x,y};
                }
            }
            q.pop();
            x=q.front().first;
            y=q.front().second;
            if(x == B.first && y == B.second) break;
        }
    }
    if(q.empty()){
        cout<<"NO"<<endl;
    }
    cout<<"YES"<<endl;
    cout<<dist<<endl;
    string path;
    int x = B.first;
    int y = B.second;
    while(!(x == -1 && y == -1)){
        int px = grid_path[x][y].first;
        int py = grid_path[x][y].second;
        if(x == px+1) 
        path.push_back('D');
        else if(x == px-1) 
        path.push_back('U');
        else if(y == py+1)
        path.push_back('R');
        else if(y == py-1) 
        path.push_back('L');
        x = px;
        y = py;
    }
    reverse(path.begin(),path.end());
    cout<<path<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n,string(m,'#'));
    vector<vector<pair<int,int>>> grid_path(n,vector<pair<int,int>>(m,{-1,-1}));
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
    int dist=0;
    queue<pair<int,int>> q;
    q.push(A);
    bfs(grid,grid_path,q,dist);
    return 0;
}