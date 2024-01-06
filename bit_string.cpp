#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int MOD =  1e9+7;

long long power(long long x, int y){
    if(y == 0){
        return 1;
    }
    return y&1 ? (x * power((x*x) %MOD,y>>1)) %MOD : power((x*x) %MOD,y>>1) %MOD;
}

// long long power(long long x,long long y){
//     if(y == 0){
//         return 0;
//     }
//     long long ans = 1;
//     for(int i=1;i<=y;i++){
//         ans = ( ans * 2 ) % MOD;
//     }
//     return ans % MOD;
// }

int main(){
    long long n;
    cin>>n;
    cout<<power(2,n);
    return 0;
}