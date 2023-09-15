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
string x;
int n;
int a[3];
bool ok (int len)
{
  a[0] = a[1] = a[2] = 0;
  for (int i = 0; i < len -1; i++)
  {
    a[x[i]-'1']++;
  }
  for (int i =0, j = len-1; j < n; i++, j++)
  {
    a[x[j]-'1']++;
    if (a[0] && a[1] && a[2])return 1;
    a[x[i]-'1']--;
  }
  return 0;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> x;
    n = SZ(x);
    int l = 3, r = n, m, ans = 0;
    while (l <= r)
    {
       m = (l+r)>>1;
       if (ok(m))
       {
         ans = m;
         r = m-1;
       }else
       l = m+1;
    }
    cout << ans <<"\n";
  }
 
}
