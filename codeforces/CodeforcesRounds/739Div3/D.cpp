// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string x, y;
int solve1()
{
    int i = 0, j = 0;
    int need = 0;
    while(i < x.size() && j < y.size())
    {
        if (x[i] == y[j])
        {
            i++;j++;
        }else
        {
            need++;
            i++;
        }
    }
    need += (x.size() - i) + (y.size() - j);
    return need;
}
void test()
{
    cin >> x;
    int ans = 1e9;
    for(auto st: v)
    {
        y = st;
        ans = min(ans, solve1());
    }
    cout << ans <<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x = 1;
    while(x <= 1e18)
    {
        v.push_back(to_string(x));
        x *= 2;
    }
    int t;
    cin >> t;
    while(t--)
        test();
}