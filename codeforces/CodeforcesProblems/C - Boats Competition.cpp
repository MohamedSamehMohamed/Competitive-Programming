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
const int N = 200;
int n, frq[N];
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    memset(frq, 0, sizeof frq);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      frq[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 2*n; i++)
    {
      int tot = 0;
      for (int j = 1; j <= n; j++)
      {
        for (int k = j; k <= n; k++)
        {
          if (j + k > i)break;
          if (j + k < i)continue;
          int cur = min(frq[j], frq[k]);
          if (j == k)cur = (frq[j]/2);
          tot += cur;
        }
      }
      ans = max(ans, tot);
    }
    cout << ans <<"\n";
  }
}
