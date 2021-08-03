// problemLink: https://codeforces.com/contest/948/problem/A
#include<bits/stdc++.h>
using namespace std;
const int N = 509;
int n, m;
string g[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> g[i];

    bool bad = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(min(nx, ny) < 0 || nx >= n || ny >= m)continue;
                    if (g[nx][ny] == '.')
                    {
                        g[nx][ny] = 'D';
                    }else
                    {
                        if (g[nx][ny] == 'W')
                        {
                            bad = 1;
                        }
                    }
                }
            }
        }
    if (bad)
    {
        cout <<"No\n";
    }else
    {
        cout <<"Yes\n";
        for(int i = 0; i < n; i++)
            cout << g[i] << "\n";
    }
    return 0;
}
