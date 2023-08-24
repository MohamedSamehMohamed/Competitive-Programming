// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9;
int a[N], b[N], n, m;
vector<pair<int,float>> v;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    v.clear();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a+i);
      b[i] = (a[i] != i+1);
      if (i)b[i] += b[i-1];
    }
    for (int i = 0; i < m; i++)
    {
      int c;
      float p;
      scanf("%d %f",&c, &p);
      v.push_back({c, p});
    }
    vector<float> tk;
    int lst = -1;
    for (int i = 0; i < m; i++)
    {
      int c = v[i].first - 1;
      float p = v[i].second;
      int bad = b[c];
      if (bad != lst && bad)
      {
        tk.push_back(p);
        if (p == 1)while(!tk.empty())tk.pop_back();
        lst = bad;
      }
      if (c == n-1)break;
    }
    double ans = (tk.size()? tk[0]: 1);
    for (int i = 1; i < tk.size(); i++)ans *= tk[i];
    if (tk.size() > 1)
      ans += ans/tk.size();
    printf("%.6f\n", ans);
  }
}
