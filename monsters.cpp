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


bool check(int n,int m,int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

vector<pair<int,int>> moves={{0,1},{0,-1},{1,0},{-1,0}}; 

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    char grid[n][m];
    memset(grid,'#',sizeof(grid));
    pair<int,int> A;
    queue<pair<int,int>> mq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] =='A'){
                A.first= i;
                A.second = j;
            }
            if(grid[i][j] == 'M'){
                mq.push({i,j});
            }
            // cout<<grid[i][j]<<" ";
        }
        // cout<<endl;
    }
    // vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int,int>> aq;
    aq.push(A);
    if(A.first == n-1 || A.first == 0 || A.second == m-1 || A.second == 0){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0; 
    }
    // visited[A.first][A.second]=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    pair<int,int> reached = {INT_MIN,INT_MIN};
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,make_pair(INT_MIN,INT_MIN)));
    while(!aq.empty()){
        int sz = aq.size();
        if(reached.first != INT_MIN && reached.second != INT_MIN) break;   
        for(int i=0;i<sz;i++){
            int x = aq.front().first;
            int y = aq.front().second;
            // visited[x][y] = 1;
            // grid[x][y] = 'A'; 
            for(auto mv:moves){

                if(reached.first != INT_MIN && reached.second != INT_MIN) break;
                if(check(n,m,x+mv.first,y+mv.second) && grid[x+mv.first][y+mv.second] ==  '.'){
                    bool isKilled = false;
                    for(auto mv2:moves){
                        if(check(n,m,x+mv.first+mv2.first,y+mv.second+mv2.second) && grid[x+mv.first+mv2.first][y+mv.second+mv2.second] == 'M'){
                            isKilled = true;
                        }
                    }
                    if(!isKilled){
                        aq.push({x+mv.first,y+mv.second});
                        grid[x+mv.first][y+mv.second] = 'A'; 
                        parent[x+mv.first][y+mv.second] = {x,y};
                        if(x+mv.first == n-1 || x+mv.first == 0 || y+mv.second == m-1 || y+mv.second == 0){
                            reached.first = x+mv.first;
                            reached.second = y+mv.second; 
                        }
                    }
                }
            }
            // if(reached.first != INT_MIN && reached.second != INT_MIN) break;
            aq.pop();
        }
        // cout<<reached.first<<reached.second<<endl;   
        sz = mq.size();
        for(int i=0;i<sz;i++){
            int x = mq.front().first;
            int y = mq.front().second;
            // visited[x][y] = 1;
            // grid[x][y] = 'A'; 
            for(auto mv:moves){
                if(check(n,m,x+mv.first,y+mv.second) && (grid[x+mv.first][y+mv.second] ==  '.' || grid[x+mv.first][y+mv.second] ==  'A')){
                    if(x+mv.first == reached.first && y+mv.second == reached.second){
                        cout<<"NO"<<endl;                       
                        return 0;
                    }
                    grid[x+mv.first][y+mv.second] = 'M'; 
                    mq.push({x+mv.first,y+mv.second});
                }
            }
            mq.pop();
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<parent[i][j].first<<","<<parent[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }
    string path;
    int x = reached.first;
    int y = reached.second;
    if(x == INT_MIN && y == INT_MIN){
        cout<<"NO"<<endl;
        return 0;
    }
    
    while(!(x == INT_MIN && y == INT_MIN)){
        int px = parent[x][y].first;
        int py = parent[x][y].second;
        // cout<<x<<" "<<y<<" "<<px<<" "<<py;
        if(px == x-1){
            path.push_back('D');
        }
        else if(px == x + 1){
            path.push_back('U');
        }
        else if(py == y + 1){
            path.push_back('L');
        }
        else if(py == y-1){
            path.push_back('R');
        }
        // cout<<path;
        // return 0;
        x = px;
        y = py;
    }   
    reverse(path.begin(),path.end());
    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
    return 0;
}   