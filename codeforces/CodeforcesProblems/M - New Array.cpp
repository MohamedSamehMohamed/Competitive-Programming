// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int t, n, q;
set<int> st;
int ans[N], id, seen[N];
int main()
{
  scanf("%d", &t);
  while(t--)
  {
    id++;
    scanf("%d%d", &n, &q);
    while(q--)
    {
      int x;
      scanf("%d", &x);
      int cur = x;
      if (seen[cur] == id)continue;
      seen[cur] = id;
      while(cur <= n)
      {
        ans[cur] = id;
        cur += x;
      }
    }
    for (int i = 1; i <= n; i++)
      printf("%d ", (ans[i] == id? 1: 0));
    printf("\n");
  }
}
