// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int main()
{
  int cur, tar, n;
  int Mx ;
  int T = 0;
  while (cin >> cur >> tar >> n)
  {
    T++;
    if (cur + tar + n == 0)break;
    cout <<"Case " << T <<": ";
    map<int,bool> seen;
    queue<pair<int,int>> q;
    q.push({cur, 0});
    seen[cur] = 1;
    vector<int> ch(n);
    Mx = tar + 1;
    for (int i = 0; i < n; i++)cin >> ch[i];
    int ans = -1;
    while(!q.empty())
    {
      pair<int,int> node = q.front();
      q.pop();
      if (node.f == tar)
      {
        ans = node.s;
        break;
      }
      //if (node.f > Mx)continue;
      for (int i: ch)
      {
        int nv = node.f + i;
        nv %= 10000;
        if (seen.find(nv) == seen.end())
        {
          seen[nv] = 1;
          q.push({nv, node.s+1});
        }
      }
    }
    if (~ans)
    cout << ans <<"\n";
    else
    cout <<"Permanently Locked\n";
  }
}
