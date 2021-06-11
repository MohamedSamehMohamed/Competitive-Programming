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
int a[N], n, m, d;
ll sum;
int main()
{
  cin >> n >> d >> m;
  for (int i = 0; i < n; i++) cin >> a[i], a[i]*=-1;
  sort(a, a+n);
  vector<ll> v(n+1);
  for (int i = 0; i < n; i++)v[i+1] = v[i] - a[i];
  int bad = 0;
  while(bad < n && -a[bad] > m)bad++;
  int leave = 0;
  for (int i = 0; i <= bad; i++)
  {
    if (i + leave > n)break;
    int r = min(n, n - leave + bad - i);
    ll cur = v[i] + v[r] - v[bad];
    sum = max(sum, cur);
    leave += d * (i > 0);
  }
  cout << sum << "\n";
}
