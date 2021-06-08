// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e3 + 9;
int a[N], n, x, k;
long long dp[N][2], inf = 1e16;
struct maxQ
{
  stack<pair<int, int>> s1, s2;
  queue<int> pos;
  int l;
  maxQ(){}
  maxQ(int level)
  {
      l = level;
  }
  int size()
  {
    return s1.size() + s2.size();
  }
  bool empty()
  {
    return size() == 0;
  }
  long long Max()
  {
    if (empty())return -inf;
    long long ms1 = -inf;
    long long ms2 = -inf;
    if (!s1.empty())ms1 = s1.top().second;
    if (!s2.empty())ms2 = s2.top().second;
    ms1 = (ms1 == -inf? -inf: dp[ms1][l]);
    ms2 = (ms2 == -inf? -inf: dp[ms2][l]);
    return max(ms1, ms2);
  }
  void push(int idx)
  {
    pos.push(idx);
    if (s2.empty())
    {
      s2.push({idx, idx});
    }else
    {
      s2.push({idx, dp[idx][l] > dp[s2.top().second][l]? idx: s2.top().second});
    }
  }
  void pop()
  {
    if (s1.empty())
    {
      while(!s2.empty())
      {
        if (s1.empty())
        {
          s1.push({s2.top().first, s2.top().first});
        }else
        {
          s1.push({s2.top().first, dp[s1.top().second][l] > dp[s2.top().first][l]? s1.top().second: s2.top().first});
        }
        s2.pop();
      }
    }
    s1.pop();
    pos.pop();
  }
  int top()
  {
    return pos.front();
  }
};
int main()
{
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
      dp[i][0] = (i < k? a[i]: -inf);
  int p = 0;
  for (int j = 1; j <= x; j++)
  {
    maxQ q(p);
    p ^= 1;
    q.push(0);
    for (int i = 1; i < n; i++)
    {
      dp[i][p] = -inf;
      while(!q.empty() && q.top() < max(0, i-k))q.pop();
      dp[i][p] = q.Max() + a[i];
      q.push(i);
    }
  }
  long long ans = -1;
  for (int i = n-k; i < n; i++)
    ans = max(ans, dp[i][p^1]);
  printf("%lld\n", ans);
}
