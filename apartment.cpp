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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> aps(n);
    vector<int> apr(m);
    for(int i=0;i<n;i++){
        cin>>aps[i];
    }
    for(int i=0;i<m;i++){
        cin>>apr[i];
    }
    sort(aps.begin(),aps.end());
    sort(apr.begin(),apr.end());
    int i=0,j=0;
    // O(m+n)
    if(aps[n-1]<apr[0]-k || aps[0] > apr[m-1]+k){
        cout<<0<<endl;
        return 0;
    }
    int count=0;
    while(j<m && i<n){
        if(apr[j] - k <= aps[i] && aps[i] <= apr[j] + k){
            count++;
            i++;
            j++;
        }
        else if(apr[j]+k < aps[i]){
            j++;
        }
        else if(apr[j]-k > aps[i]){
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}