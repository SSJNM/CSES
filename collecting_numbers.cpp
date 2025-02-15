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

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    int count=1;
    for(int i=1;i<n;i++){
        if(v[i].second < v[i-1].second){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}