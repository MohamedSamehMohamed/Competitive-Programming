// https://codeforces.com/gym/102944/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 2009;
int ans[N][N], vis[N][N];
int n, m;
char x[N];
string g[N];
bool dfs(int i, int j)
{
    if (min(i, j) < 0 || i >= n || j >= m)return 0;
    if (vis[i][j])
        return ans[i][j] == -1? 1: ans[i][j];
    vis[i][j] = 1;
    if (g[i][j] == 'S')
    {
        ans[i][j] = dfs(i+1, j);
    }else if (g[i][j] == 'W')
    {
        ans[i][j] = dfs(i, j-1);
    }else if (g[i][j] == 'E')
    {
        ans[i][j] = dfs(i, j+1);
    }else
    {
        ans[i][j] = dfs(i-1, j);
    }
    return ans[i][j];
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", x);
        g[i] = x;
    }
    memset(ans, -1, sizeof ans);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if (ans[i][j] == -1)
            {
                ans[i][j] = dfs(i, j);
            }
        }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)cnt += ans[i][j];

    printf("%d\n", cnt);

    return 0;
}
