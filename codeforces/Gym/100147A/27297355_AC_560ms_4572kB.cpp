// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  int n;
  scanf("%d", &n);
  vector<pair<int,int>> v(n);
  map<int,int> R, C;
  for (int i = 0; i < n; i++)scanf("%d%d", &v[i].f, &v[i].s);
  for (int i = 0; i < n; i++)
  {
    R[v[i].f]++;
    C[v[i].s]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += 1LL * (R[v[i].f]-1) * (C[v[i].s]-1);
  }
  printf("%lld\n", ans);
}
/*
6
0 0
0 1
0 2
1 0
2 0
1 1
*/
