// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 17, Lg = 17;
int a[N], spt[N][Lg], Log[N], n, q;
void build()
{
	for (int i = 2; i < N; i++)
		Log[i] = Log[i>>1] + 1; 
	for (int i = 0; i < n; i++)
		spt[i][0] = a[i];
	for (int j = 1; j < Lg; j++)
		for (int i = 0; (1<<j) + i <= n; i++)
			spt[i][j] = __gcd(spt[i][j-1], spt[i+(1<<(j-1))][j-1]); 
}
int query(int l, int r)
{
	int sz = Log[r-l+1]; 
	return __gcd(spt[l][sz], spt[r-(1<<sz)+1][sz]); 
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++)
		v.push_back({a[i], i}); 
	sort(v.begin(), v.end()); 
	build();
	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int g = query(l-1, r-1);
		int c = upper_bound(v.begin(), v.end(), make_pair(g, r-1)) - lower_bound(v.begin(), v.end(), make_pair(g, l-1)); 
		printf("%d\n", r-l+1-c);
		
	}
}
