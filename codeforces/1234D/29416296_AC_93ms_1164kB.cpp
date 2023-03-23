// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 17;
int seg[N<<1]; 
char x[N];
int n, q; 
int msk(char c){return (1<<(c-'a'));} 
void build(int node = 0, int l = 0, int r = n-1)
{
	if (l == r)
	{
		seg[node] = msk(x[l]); 
		return;
	}
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	build(n1, l, m);
	build(n2, m+1, r);
	seg[node] = seg[n1]|seg[n2]; 
}
void update(int pos, int p, int node = 0, int l = 0, int r = n-1)
{
	if (l > pos || r < pos)return;
	if (l == r)
	{
		seg[node] = 1 << p; 
		return;
	}
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	update(pos, p, n1, l, m);
	update(pos, p, n2, m+1, r);
	seg[node] = seg[n1]|seg[n2]; 
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
	if (le > r || re < l)return 0; 
	if (l >= le && r <= re)return seg[node];
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	return query(le, re, n1, l, m)|query(le, re, n2, m+1, r); 
}
int main()
{
	scanf(" %s", x);
	n = strlen(x);
	build();
	auto ans = [](int x)
	{
	  int cnt = 0;
	  for (int i = 0; i < 26; i++)
		cnt += ((x&(1<<i))!=0);
	  return cnt; 
	};
	scanf("%d", &q);
	while(q--)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			int pos;
			char c;
			scanf("%d %c", &pos, &c); 
			update(pos-1, c-'a'); 
		}else 
		{
		  int l, r;
		  scanf("%d%d", &l, &r);
		  printf("%d\n", ans(query(l-1, r-1))); 
		}
	}
}
