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

int score(vector<int>& board,int i,int j){
    int s1 = board[i] + score(board,i+1,j);
    int s2 = board[j] + score(board,i,j-1);
    
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<score(v,0,n-1);
    return 0;
}