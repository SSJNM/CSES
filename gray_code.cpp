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

vector<string> gray_code(int n){
    if(n == 1){
        return {"0","1"};
    }
    vector<string> prev = gray_code(n-1);
    vector<string> ans;
    int count=0;
    for(int i=0;i<prev.size();i++){
        ans.push_back(prev[i]+"0");   
    }
    for(int i=prev.size()-1;i>=0;i--){
        ans.push_back(prev[i]+"1");   
    }
    return ans;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector<string> ans=gray_code(n);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}