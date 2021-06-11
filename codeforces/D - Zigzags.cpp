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
const int N = 3009;
int n, a[N], l[N], r[N];
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", a+i);
    memset(l, 0, sizeof l);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      memset(r, 0, sizeof r);
      for (int j = n-1; j > i; j--)
      {
        ans += l[a[j]] * r[a[i]];
        r[a[j]]++;
      }
      l[a[i]]++;
    }
    cout << ans <<"\n";
  }
}
