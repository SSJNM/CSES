#include <bits/stdc++.h>
using namespace std;

void digit_converter(int num,string& digits){
    int p = digits.size()-1;
    while(num>0){
        digits[p] = '0' + num%10;
        num = num/10;
        p--;
    }
}

void digit_print(string& d){
    for(auto x:d){
        cout<<x<<endl;  
    }
}

int steps_calculate(int num, string digits){
    if(num<=0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=0;i<digits.size();i++){
        if(digits[i]-'0' != 0){
            // cout<<num - digits[i]-'0'<<endl;
            digit_converter(num - digits[i]-'0',digits);
            ans = min(ans,1+steps_calculate(num-digits[i]-'0',digits));
            digit_converter(num,digits);
        }
    }
    return ans;
}


int main(){
    int num;
    cin>>num;
    string digits = "0000000";
    digit_converter(num,digits);
    cout<<steps_calculate(num,digits);    
    return 0;
}