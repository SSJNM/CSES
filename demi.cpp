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

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<vector<int>> lookup(grid.begin(),grid.end());
        for(int i=0;i<grid[0].size();i++){
            int total=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]) total++;
            }
            for(int j=0;j<grid.size();j++){
                if(grid[j][i])
                lookup[j][i] = total-1;
            }
        }
        long long ans=0;
        for(int i=0;i<grid.size();i++){
            int o=-1,t=-1;
            for(int j=0;j<grid[0].size();j++){
                if(o == -1 && grid[i][j]) o = j;
                else if(t == -1 && grid[i][j]) t = j;
                else{
                    o = t;
                    t = -1;
                }
            }
        }
        return ans;
    }
};

int main(){
    fast_cin();
    
    return 0;
}