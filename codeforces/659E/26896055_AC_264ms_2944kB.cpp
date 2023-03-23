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
const int N = 1e5+9;
int par[N], size[N], ed[N];
int n, m;
void init()
{
	for (int i = 0; i < N; i++)
	{
		par[i] = i;
		size[i] = 1;
		ed[i] = 0;
	}
}
int get_par(int u)
{
	return u == par[u] ? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
	u = get_par(u);
	v = get_par(v);
 	if (u == v)return 0;
	par[u] = v;
	size[v] += size[u];
	ed[v] += ed[u] + 1;
	return 1;
}
int main()
{
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (!uni(u, v)) ed[get_par(u)]++;
	}
	set<int> P;
	for (int i = 1; i <= n; i++)P.insert(get_par(i)); 
	int ans = 0;
	for (int i: P)
	{
		ans += (size[i] > ed[i]);
	}
	cout << ans << '\n'; 
}
