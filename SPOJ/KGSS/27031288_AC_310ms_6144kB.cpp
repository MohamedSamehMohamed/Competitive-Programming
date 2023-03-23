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
int n, m;
pair<int,int> seg[4*N];
int a[N];
vector<int> v;
pair<int,int> compine(pair<int,int> l, pair<int,int> r)
{
	v.clear();
	v.pb(l.f);
	v.pb(l.s);
	v.pb(r.f);
	v.pb(r.s);
	sort(all(v));
	return {v[3], v[2]};
}
void build(int node = 0, int l = 0, int r = n-1)
{
	if (l == r)
	{
		seg[node] = {a[l],-1};
		return;
	}
	int m = (l+r)>>1;
	build(node * 2 + 1, l, m);
	build(node * 2 + 2, m+1, r);
	seg[node] = compine(seg[node*2+1], seg[node*2+2]);
}
pair<int,int> query(int node, int l, int r, int l1, int r1)
{
	if (l > r1 || r < l1)return {-1, -1};
	if (l >= l1 && r <= r1)return seg[node];
	int m = (l+r)>>1;
	return compine(query(node * 2 + 1, l, m, l1, r1), query(node * 2 + 2, m+1, r, l1, r1));
}
int query_helper(int l, int r)
{
	pair<int,int> ret = query(0, 0, n-1, l, r);
	return ret.f + ret.s;
}
void update(int node, int l, int r, int idx, int val)
{
	if (l > idx || r < idx)return;
	if (l == r)
	{
		seg[node] = {val, -1};
		return;
	}
	int m = (l+r)>>1;
	update(node * 2 + 1, l, m, idx, val);
	update(node * 2 + 2, m+1, r, idx, val);
	seg[node] = compine(seg[node*2+1], seg[node*2+2]);
}
void update_helper(int idx, int val)
{
	update(0, 0, n-1, idx, val);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	build();
	cin >> m;
	while(m--)
	{
		int x, y;
		char op;cin >> op >> x >> y;
		if (op == 'U')update_helper(x-1, y);
		else 
		{
			cout << query_helper(x-1, y-1) << '\n';
		}
	}
}
