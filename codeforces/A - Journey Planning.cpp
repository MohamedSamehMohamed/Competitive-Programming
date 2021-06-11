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
const int N = 4e5 + 1;
map<ll, ll> frq;
ll ans;
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    ans = max(ans, 1LL*val);
    frq[val-i-1]+=val;
  }
  for (auto i: frq)ans = max(ans, i.s);
  printf("%lld\n", ans);
}
