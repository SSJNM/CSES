#include<bits/stdc++.h>
using namespace std;


pair<int,int> A;
pair<int,int> B;


vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};

bool check(vector<string>& grid,int x,int y){
    return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
}

void bfs(vector<string>& grid,vector<vector<pair<int,int>>>& grid_path,queue<pair<int,int>>& q,int& dist){
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int x=q.front().first;
            int y=q.front().second;
            if(x == B.first && y == B.second) return;
            grid[x][y] = '#';
            q.pop();
            for(auto d:dir){
                if(check(grid,x+d.first,y+d.second) && grid[x+d.first][y+d.second] != '#'){
                    q.push({x+d.first,y+d.second});
                    grid_path[x+d.first][y+d.second].first = x;
                    grid_path[x+d.first][y+d.second].second = y;
                    grid[x+d.first][y+d.second] = '#';
                }
            }
        }
        dist++;
    }
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
    // for(auto x:grid_path){
    //     for(auto y:x){
    //         cout<<"{"<<y.first<<","<<y.second<<"} ";
    //     }
    //     cout<<endl;
    // }
    grid_path[A.first][A.second] = {A.first,A.second};
    if(q.empty()){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    string path;
    int x = B.first;
    int y = B.second;
    int px = grid_path[x][y].first;
    int py = grid_path[x][y].second;
    while(!(x == px && y == py)){
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
        px = grid_path[x][y].first;
        py = grid_path[x][y].second;
    }
    reverse(path.begin(),path.end());
    cout<<dist<<endl;
    cout<<path<<endl;
    return 0;
} 