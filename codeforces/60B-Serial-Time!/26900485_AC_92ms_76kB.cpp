// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 10;
int g[N][N][N];
int vis[N][N][N];
int n, m, k;
int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};
void dfs(int l, int x, int y)
{
	vis[l][x][y] = 1;
	for (int i = 0; i < 5; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (min(nx, ny) < 0|| nx >= n|| ny >= m)continue;
		for (int lev = -1; lev <= 1; lev++)
		{
			if (lev != 0 && i != 4)continue;
			int nl = l + lev;
			if (nl < 0 || nl >= k)continue;
			if (vis[nl][nx][ny] || !g[nl][nx][ny])continue;
			dfs(nl, nx, ny);
		}
	}
}
int main()
{
	cin >> k >> n >> m;
	for (int kth = 0; kth < k; kth++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				char c;cin >> c;
				g[kth][i][j] = (c == '.'); 
			}
	}
	int stx, sty;
	cin >> stx >> sty;
	stx--;sty--;
	dfs(0, stx, sty);
	int ans = 0;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				ans += vis[i][j][l];
	cout << ans << '\n';
}
