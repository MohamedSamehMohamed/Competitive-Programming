// problemLink: https://codeforces.com/gym/102944/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m;
string g[N];
vector<pair<int, int>> v;
int ans = 1e9;
int vis[N][N], vid;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j)
{
    if (vis[i][j] == vid)
        return;
    vis[i][j] = vid;
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (min(nx, ny) < 0 || nx >= n || ny >= m || g[nx][ny] != g[i][j])continue;
        dfs(nx, ny);
    }
}
void test()
{
    vid++;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if (vis[i][j] != vid)
            {
                dfs(i, j);
                cnt++;
            }
        }
    ans = min(ans, cnt);
}
void solve(int i = 0)
{
    if (i == v.size())
    {
        test();
        return;
    }
    g[v[i].first][v[i].second] = '0';
    solve(i+1);
    g[v[i].first][v[i].second] = '1';
    solve(i+1);
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> g[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (g[i][j] == '?')v.push_back({i, j});
    solve();
    cout << ans << "\n";

}
