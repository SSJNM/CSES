#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


vector<pair<int,int>> tower(int n,int u,int v,int w){
    if(n == 1){
        return {{u,w}};
    }
    else if(n == 2){
        return {{u,v},{u,w},{v,w}};
    }
    vector<pair<int,int>> a;
    vector<pair<int,int>> a2 = tower(n-1,u,w,v);
    pair<int,int> p = {u,w};
    vector<pair<int,int>> a3 = tower(n-1,v,u,w);        
    for(int i=0;i<a2.size();i++){
        a.push_back({a2[i].first,a2[i].second});
    }
    a.push_back(p);
    for(int i=0;i<a3.size();i++){
        a.push_back({a3[i].first,a3[i].second});
    }
    return a;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector<pair<int,int>> ans = tower(n,1,2,3);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    } 
}