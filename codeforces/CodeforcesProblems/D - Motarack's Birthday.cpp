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
const int N = 1e5+9;
int a[N], n, b[N];
ll cal(int x)
{
  for (int i = 0; i < n; i++)
  b[i] = (a[i] == -1? x : a[i]);
  ll mx = 0;
  for (int i = 0; i+1 < n; i++)
    mx = max(mx, 1LL*abs(b[i] - b[i+1]));
  return mx;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mn, mx;
    mn = 1e9+1;
    mx = -1;
    for (int i = 0; i < n; i++)
    {
      if (a[i] != -1)continue;
      int j = i+1;
      while(j < n && a[j] == -1)j++;
      j--;
      int l, r;
      l = r = -1;
      if (i-1 >= 0)l = a[i-1];
      if (j+1 < n )r = a[j+1];
      if (l!=-1)
      {
        mn = min(mn, l);
        mx = max(mx, l);
      }
      if (r != -1)
      {
        mn = min(mn, r);
        mx = max(mx, r);
      }
      i = j;
    }
    vector<int> v(3);
    if (mx == -1)
    {
      mn = mx = 1;
    }
    mx = (mn + mx)/2;
    v[0] = mx - 1;
    v[1] = mx;
    v[2] = mx+1;
    int cur = 1e9;
    int id = 0;
    for (int i = 0; i < 3; i++)
    {
      if (v[i] < 0 || v[i] > (int)1e9)continue;
      int c = cal(v[i]);
      if (c < cur)
      {
        cur = c;
        id = i;
      }
    }
    cout << cur << " " << v[id] << "\n";
 
  }
 
}
