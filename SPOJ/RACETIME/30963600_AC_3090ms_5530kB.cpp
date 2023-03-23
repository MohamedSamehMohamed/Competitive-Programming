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
const int N = 1e5+9, block_sz = (int)(sqrt(N)+1);
int n, m;
int a[N], sz;
vector<int> blocks[block_sz];
void update(int idx, int val)
{
	for (int i = 0; i < SZ(blocks[idx/sz]); i++)
	{
		if (blocks[idx/sz][i] == a[idx])
		{
			blocks[idx/sz].erase(blocks[idx/sz].begin() + i);
			break;
		}
	}
	blocks[idx/sz].pb(val);
	sort(all(blocks[idx/sz]));
	a[idx] = val;
}
int BS(int idx, int val)
{
	int l = 0, r = SZ(blocks[idx])-1, m, ans = -1;
	while(l <= r)
	{
		m = (l+r)>>1;
		if (blocks[idx][m] <= val)ans = m, l = m+1;
		else
		r = m-1;
	}
	return ans + 1;
}
int query(int l, int r, int val)
{
	int ans = 0;
	while(l <= r)
	{
		if (l%sz == 0 && l + sz - 1 <= r)
		{
			ans += BS(l / sz, val);
			l += sz;
		}else
		{
			ans += (a[l] <= val);
			l++;
		}
	}
	return ans;
}
void debug()
{
	cout <<"DEB\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j: blocks[i])cout << j <<" ";
		cout <<"\n";
	}
	cout <<"DEB\n";
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", a+i);
	sz = (int)(sqrt(n)+1);
	for (int i = 0; i < n; i++)
	{
		blocks[i/sz].pb(a[i]);
	}
	for (int i = 0; i < block_sz; i++)sort(all(blocks[i]));
	while(m--)
	{
		int l, r, x;
		char ty;
		cin >> ty;
		if (ty == 'M')
		{
			scanf("%d%d", &l, &x);
			l--;
			update(l, x);
		}else
		{
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", query(l-1, r-1, x));
		}
	//	debug();
	}
}
