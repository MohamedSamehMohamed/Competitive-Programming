// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int n, k;
string x, y;
int frq[26];
int frq1[26];
int main()
{
  int t;cin >> t;
  while(t--)
  {
    cin >> n >> k >> x >> y;
    memset(frq, 0, sizeof frq);
    memset(frq1, 0, sizeof frq1);
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      frq[x[i] - 'a']++;
      frq1[y[i] - 'a']++;
    }
    int extra = 0;
    int totneed = 0;
    for (int i = 0; i < 26; i++)
    {
      if (frq[i] == frq1[i])
        continue;
      if (frq[i] > frq1[i])
      {
        int cur = frq[i] - frq1[i];
        extra += cur;
        ok &= (cur % k == 0);
      }else
      {
        int need = frq1[i] - frq[i];
        ok &= (need % k ==0);
        totneed += need;
        if (totneed > extra)
        {
          ok = 0;break;
        }
      }
    }
    if (extra % k || totneed != extra)ok = 0;
    if (ok)
      cout <<"Yes\n";
    else
      cout <<"No\n";
  }
}
