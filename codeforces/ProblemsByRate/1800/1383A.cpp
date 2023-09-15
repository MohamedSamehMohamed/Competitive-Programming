#include <bits/stdc++.h>
using namespace std;
string a, b;
vector<int> adj[20];
int msk[20], n;
bool dfs(int from, int to, int seen)
{
    if (msk[from] & (1<<to))
        return 1;
    for(int i = 0; i < 20; i++)
    {
        if (seen & (1<<i))continue;
        if (msk[from] & (1<<i))
        {
            if (dfs(i, to, seen | (1<<i)))
                return 1;
        }
    }
    return 0;
}
void test()
{
    for(int i = 0; i < 20; i++) {
        adj[i].clear();
        msk[i] = 0;
    }
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        if (a[i] > b[i])
        {
            cout <<"-1\n";
            return;
        }
    for(int i = 0; i < n; i++)
        if (b[i] != a[i])
            adj[b[i] - 'a'].push_back(i);

    int ans = 0;
    for(int i = 0; i < 20; i++)
    {
        if (adj[i].size() == 0)continue;
        int curMsk = 0;
        for(int j: adj[i])
            curMsk |= (1<<(a[j]-'a'));

        curMsk |= (1<<i);
        vector<pair<int, int>> temp;
        for(int from = 0; from < 20; from++) {
            if (!(curMsk & (1 << from)))continue;
            bool reach = 0;
            for(int to = from + 1; !reach && to < 20; to++)
            {
                if (!(curMsk & (1 << to)))continue;
                reach = dfs(from, to, (1<<from));
                msk[from] |= reach * (1<<to);
            }
            if (reach)
            {
                curMsk ^= (1<<from);
                continue;
            }
            for (int to = from + 1; to < 20; to++) {
                if (!(curMsk & (1 << to)))continue;
                msk[from] |= (1 << to);
                temp.push_back({to, 1<<from});
            }
        }
        for(auto jj: temp)
            msk[jj.first] |= jj.second;
        ans += __builtin_popcount(curMsk) - 1;
    }
    cout << ans << "\n";
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        test();
}