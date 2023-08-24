// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int dp[10009];
bool ok(int x, int d)
{
  vector<int> v;
  for (int i = 1; i <= x/i; i++)
  {
    if (x % i == 0)
    {
      v.push_back(i);
      if (x/i != i)v.push_back(x/i);
    }
  }
  if (v.size() < 4)return 0;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v.size(); j++)
    {
      if (i == j)continue;
      if (abs(v[i] - v[j]) < d)return 0;
    }
  }
  return 1;
}
int broute(int x)
{
  if (~dp[x])return dp[x];
  for (int i = 1; ; i++)
  {
    if (ok(i, x))
      return dp[x] = i;
  }
}
int main()
{
  memset(dp, -1, sizeof dp);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    int ans = broute(n);
    set<int> st;
    for (int i = 1; i <= ans/i; i++)
    {
      if (ans % i == 0)
      {
        st.insert(i);
        st.insert(ans/i);
      }
    }
    for (auto i: st)cout << i <<" ";
    cout <<"\n";
    printf("%d\n", ans);
  }
}
