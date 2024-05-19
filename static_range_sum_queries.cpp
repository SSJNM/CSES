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

int main(){
    fast_cin();
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<ll> ps(n+1,0);
    ps[1] = v[1];
    for(ll i=2;i<=n;i++){
        ps[i] = ps[i-1] + v[i];
    }
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<ps[b]-ps[a-1]<<endl;
    }
    return 0;
}