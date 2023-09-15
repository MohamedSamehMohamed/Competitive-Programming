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
const int N = 2e5+9;
int a[N], n, Mx[N];
void solve()
{
  cin >> n;
  Mx[0] = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    Mx[i] = a[i];
    if (i)Mx[i] = max(Mx[i], Mx[i-1]);
  }
  ll ans = 0;
  int lst = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == Mx[i]){
      lst = 0;
      continue;
    }
    int j = i+1;
    while(j < n && Mx[j] != a[j] && a[j] >= a[j-1])j++;
    ans += (Mx[i] - a[i]) - lst;
    i = j-1;
    lst = Mx[i] - a[i];
  }
  cout << ans <<"\n";
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)solve();
}
