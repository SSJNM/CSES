#include <bits/stdc++.h>
using namespace std;

int printer(long long num,long long r){
    if(r == 1){
        return num%10;
    }
    return printer(num/10,--r);
}

int main(){
    int T;
    // cin>>T;
    T = 200;
    long long num;
    // cin>>num;
    num = 180;
    for(int t=0;t<T;t++){
        num++;
        if(num<10){
            cout<<num<<endl;
            continue;
        }
        long long sum = 0;
        long long spare = 9;
        long long p = 1;
        long long prev;   
        while(sum < num){
            prev = sum;
            sum = sum + spare*p++;
            spare = spare*10;
        }
        p--;
        long long diff = num-prev-1;
        long long remainder = diff%p;
        long long fnum = pow(10,p-1) + diff/(p);
        // cout<<fnum<<endl;
        cout<<printer(fnum,p-remainder)<<endl;
    }
    return 0;
}