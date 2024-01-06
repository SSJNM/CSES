#include<bits/stdc++.h>
using namespace std;


int A_x,A_y,B_x,B_y;
string path;
bool A = false;
bool B = true;
bool isSafe(int x,int y,vector<string> & visited,vector<vector<int>>& dist){
    return ((x>=0 && x < dist.size()) && (y>=0 && y < dist[0].size()) && visited[x][y] != '#' && dist[x][y] == -1);
}

void bfs(vector<string> & visited,vector<vector<int>>& dist){
    queue<pair<int,int>> q;
    q.push({A_x,A_y});
    dist[A_x][A_y] = 0;
    while (!q.empty())
    {
        pair<int,int> pos = q.front();
        if(isSafe(pos.first-1,pos.second,visited,dist)){
            path.push_back('U');
            q.push({pos.first - 1,pos.second});
            dist[pos.first-1][pos.second] = 1 + dist[pos.first][pos.second];
        }
        if(isSafe(pos.first+1,pos.second,visited,dist)){
            path.push_back('D');
            q.push({pos.first + 1,pos.second});
            dist[pos.first+1][pos.second] = 1 + dist[pos.first][pos.second];
        }
        if(isSafe(pos.first,pos.second-1,visited,dist)){
            path.push_back('L');
            q.push({pos.first ,pos.second-1});
            dist[pos.first][pos.second-1] = 1 + dist[pos.first][pos.second];
        }
        if(isSafe(pos.first,pos.second+1,visited,dist)){
            path.push_back('R');
            q.push({pos.first ,pos.second+1});
            dist[pos.first][pos.second+1] = 1 + dist[pos.first][pos.second];
        }
        visited[pos.first][pos.second] = '#';
        // cout<<pos.first<<" "<<pos.second<<endl;
        q.pop();
    }
}

void solve(int n, int m,vector<string> & visited,vector<vector<int>>& dist){
    int count=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j] != '#'){
                bfs(visited,dist);
                if(dist[B_x][B_y] != -1){
                    cout<<"YES"<<endl;
                    cout<<dist[B_x][B_y]<<endl;
                    cout<<path<<endl;
                    return;
                }
                else{
                    cout<<"NO"<<endl;
                    return;    
                }
            }
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    vector<string> visited(n+2,string(m+2,'#'));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            cin>>visited[i][j];
            if(visited[i][j] == 'A'){
                A_x = i;
                A_y = j;
            }
            if(visited[i][j] == 'B'){
                B_x = i;
                B_y = j;
            }
        }
    }
    vector<vector<int>> dist(n+2,vector<int> (m+2,-1)); 
    solve(n+2,m+2,visited,dist);
    return 0;
}