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
const int N = 1<<19;
int n, a[N], seg[N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = 0;
    return;
  }
  int m = (l+r)>>1;
  build(node * 2 + 1, l, m);
  build(node * 2 + 2, m+1, r);
  seg[node] = seg[node*2+1] + seg[node*2+2];
}
void update(int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > val || r < val)return;
  if (l == r)
  {
      seg[node]++;
      return;
  }
  int m = (l+r)>>1;
  update(val, node * 2 + 1, l, m);
  update(val, node * 2 + 2, m+1, r);
  seg[node] = seg[node*2+1] + seg[node*2+2];
}
int query(int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > val)return 0;
  if (r <= val)return seg[node];
  int m = (l+r)>>1;
  return query(val, node * 2 + 1, l, m) + query(val, node * 2 + 2, m+1, r);
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    vector<string> s1(n), s2(n);
    for (int i = 0; i < n; i++)cin >> s1[i];
    for (int i = 0; i < n; i++)cin >> s2[i];
    map<string, int> mp;
    for (int i = 0; i < n; i++)
      mp[s1[i]] = i;
    build();
    for (int i = 0; i < n; i++)
      a[i] = mp[s2[i]];
    int ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
      ans += query(a[i]);
      update(a[i]);
    }
    cout << ans << '\n';
  }
}
