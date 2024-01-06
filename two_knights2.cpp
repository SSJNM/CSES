#include <bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin>>T;
    for(long long t=1;t<=T;t++){
        if(t == 0){
            cout<<0<<endl;
            continue;
        }
        long long ans = t*t*(t*t-1)/2 - 4*(t-1)*(t-2);
        cout<<ans<<endl; 
    }
    return 0;
}  