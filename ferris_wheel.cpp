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
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    sort(w.begin(),w.end());
    int i=0,j=n-1;
    int count=0;
    while(i<j-1){
        if(w[i] + w[j]<=x){
            i++;
            j--;
        }
        else if(w[j]<=x){
            j--;
        }
        else{
            i++;
        }
        count++;
    }
    if(w[i] + w[j]<=x){
        i++;
        j--;
        count++;
    }
    else{
        count += 2;
    }
    cout<<count<<endl;
    return 0;
}