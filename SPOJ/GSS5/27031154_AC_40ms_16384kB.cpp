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
const int N = 2e5+9;
int n, m, t, a[N];
struct tree{
	int sum, pre, suf, ans;
	tree(int sum = 0, int pre = 0, int suf = 0, int ans = 0)
	{
		this->sum = sum;
		this->pre = pre;
		this->suf = suf;
		this->ans = ans;
	}
}seg[4*N];
tree compine(tree l, tree r)
{  
	tree tot;
	tot.sum = l.sum + r.sum;
	tot.pre = max(l.pre, l.sum + r.pre);
	tot.suf = max(r.suf, r.sum + l.suf);
	tot.ans = max({l.ans, r.ans, l.suf + r.pre});
	return tot;
}
void build(int node = 0, int l = 0, int r = n-1)
{
	if (l == r)
	{
		seg[node] = tree(a[l], a[l], a[l], a[l]);
		return;
	}
	int m = (l+r)>>1;
	build(node * 2 + 1, l, m);
	build(node * 2 + 2, m+1, r);
	seg[node] = compine(seg[node * 2 + 1], seg[node * 2 + 2]);
}
tree query(int node, int l, int r, int l1, int r1)
{
	if (l > r1 || r < l1)return tree();
	if (l >= l1 && r <= r1)return seg[node];
	int m = (l+r)>>1;
	if (r1 <= m)return query(node * 2 + 1, l, m, l1, r1);
	if (l1 > m)return query(node * 2 + 2, m+1, r, l1, r1);
	return compine(query(node * 2 + 1, l, m, l1, r1), query(node * 2 + 2, m+1, r, l1, r1)); 
}
tree query_helper(int l, int r)
{
	return (l <= r? query(0, 0, n-1, l, r): tree());
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		build();
		cin >> m;
		while(m--)
		{
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--;r1--;l2--;r2--;
			int ans;
			if (r1 < l2)
			{
				ans = query_helper(l1, r1).suf + query_helper(l2, r2).pre + query_helper(r1+1, l2-1).sum;
			}else 
			{
				ans = query_helper(l2, r1).ans;
				int temp  = query_helper(l2, r2).pre + query_helper(l1, l2).suf - a[l2];
				int temp1 = query_helper(l1, r1).suf + query_helper(r1, r2).pre - a[r1];
				ans = max({ans, temp1, temp}); 
			}
			cout << ans << '\n';
		}
	}
}


