// Author: MohamedSameh
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, mod = 1e9 + 7;
int a[N], n, k;
vector<int> take;
int ways = 0;
void solve(int i = 0)
{
    if (i == n)
    {
        int an = a[0];
        int xo = a[0];
        for(int j = 1; j < n; j++)
        {
            an &= a[j];
            xo ^= a[j];
        }
        if (an >= xo)ways++;
        return;
    }
    for(int j: take)
    {
        a[i] = j;
        solve(i+1);
    }
}
void test()
{
    scanf("%d%d", &n, &k);
    teke.clear();
    for(int i = 0; i < (1<<k); i++)take.push_back(i);
    solve();
    cout << ways <<"\n";
}
int main() {


    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}