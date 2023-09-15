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
int n, b[N];
bool seen[N];
int par[N];
ll sum[N];
stack<ll> ans;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
  sum[v] += sum[u];
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < n; i++)
    cin >> sum[i];
  for (int i = n-1; i >= 0; i--)
    cin >> b[i], b[i]--;
  ll mx = 0;
  ans.push(0);
  for (int i = 0; i < n - 1; i++)
  {
    int idx = b[i];
    seen[idx] = 1;
    if (idx + 1 < n && seen[idx+1])uni(idx, idx+1);
    if (idx - 1 >= 0 && seen[idx-1])uni(idx, idx-1);
    mx = max(mx, sum[get_par(idx)]);
    ans.push(mx);
  }
  while(!ans.empty())
  {
    cout << ans.top() <<"\n";
    ans.pop();
  }
 
}
