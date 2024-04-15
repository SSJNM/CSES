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
    string str;
    cin>>str;
    vector<int> ht(26);
    for(int i=0;i<str.size();i++){
        ht[str[i]-'A']++;
    }
    int oc=0;
    int och = -1;
    for(int i=0;i<26;i++){
        if(ht[i]&1){
             oc++; och=i;
        }
    }
    if(oc>=2){
        cout<<"NO SOLUTION";
        return 0;
    }
    string ans = str;
    if(oc==1 && (str.size() & 1) ) {
        ans[str.size()/2] = och+'A';
        int sz = --ht[och];
        int l=str.size()/2-1,r=str.size()/2+1;
        while(ht[och]){
            ans[l--] = 'A' + och;
            ans[r++] = 'A' + och;
            ht[och] -= 2;
        }   
    }
    int l=0,r=str.size()-1;
    for(int i=0;i<26;i++){
        // if(och != -1 && i == och) continue;
        while(ht[i]){
            ans[l++] = 'A' + i;
            ans[r--] = 'A' + i;
            ht[i] -= 2;
        }
    }
    cout<<ans<<endl;
    return 0;
}