#include <bits/stdc++.h>
using namespace std;

void creator(vector<int> &ht, int n, string &ans, int p)
{
    cout<<n<<endl;
    if (n == 0)
    {
        cout << ans << '\n';
    }
    if (p >= 26)
    {
        return;
    }
    if (ht[p] != 0)
    {
        ans.push_back(ht[p] + 'a');
        ht[p]--;
        creator(ht, n - 1, ans, p+1);
        ht[p]++;
        ans.pop_back();
        creator(ht, n, ans, p + 1);
    }
}
int main()
{
    string str = "aaaffefjg";
    string ans;
    vector<int> ht(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        ht[str[i] - 'a']++;
    }
    creator(ht, str.size(), ans, 0);
    return 0;
}
