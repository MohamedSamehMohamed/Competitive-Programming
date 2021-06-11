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
const int N = 100;
int n, a[N];
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a+n);
    bool ok = 1;
    for (int i = 0; i < n-1; i++)
    {
      if (a[i+1] - a[i] > 1)
      {
        ok = 0;
        break;
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
