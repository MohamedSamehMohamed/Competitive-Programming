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
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int a, b, p, n;
    string x;
    cin >> a >> b >> p;
    cin >> x;
    n = SZ(x)-1;
    int ans = n+1;
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
      int j = i+1;
      while(j < n && x[j] == x[i])j++;
      tot+=(x[i] == 'A' ? a: b);
      i = j-1;
    }
    for (int i = 0; i < n; i++)
    {
      if (tot <= p)ans = min(ans, i+1);
      int j = i+1;
      while(j < n && x[j] == x[i])j++;
      tot-=(x[i] == 'A' ? a: b);
      i = j-1;
    }
    cout << ans <<"\n";
 
  }
}
