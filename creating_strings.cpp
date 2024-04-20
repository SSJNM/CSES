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


vector<string> ans; 

void solve(vector<int>& ht,string& str,string& newstr){
    if(newstr.size() == str.size()){
        ans.push_back(newstr);
        return ;
    }
    for(int i=0;i<26;i++){
        if(ht[i]){
            ht[i]--;
            newstr.push_back(i+'a');
            solve(ht,str,newstr);
            ht[i]++;
            newstr.pop_back();
        }
    }
}

int main(){
    fast_cin();
    string str;
    cin>>str;
    vector<int> ht(26,0);
    for(int i=0;i<str.size();i++){
        ht[str[i]-'a']++;
    }
    // for(auto x:ht) cout<<x<<" ";
    string newstr;
    solve(ht,str,newstr);
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}