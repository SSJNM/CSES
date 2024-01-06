#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long miniyet = arr[0];
    long long count=1;
    for(long long i=1;i<n;i++){
        if(arr[i]<miniyet){
            count++;
            miniyet = arr[i];
        }
    }
    cout<<count;
    return 0;
}