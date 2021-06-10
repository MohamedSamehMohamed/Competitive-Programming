// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
/*
a <= b <= c <= d
b+c
next will be with sum = c
so I can't get d ever so I must take the largest number as one of first pair
*/
const int N = 2e3 + 9;
int a[N], vis[N], id, n;
vector<pair<int,int>> ans;
map<int, int> mp;
bool can(int sum)
{
  ans.clear();
  mp.clear();
  for (int i = 0; i < 2 * n; i++)
    mp[a[i]]++;
  id++;
  int i = 2*n-1;
  int tk = 0;
  while(tk != n)
  {
    while(vis[i] == id || mp[a[i]] == 0)
      i--;
    mp[a[i]]--;
    vis[i] = 1;
    int need = sum - a[i];
    if (mp[need] == 0)return 0;
    mp[need]--;
    ans.push_back({a[i], need});
    sum = max(a[i], need);
    tk++;
  }
  return tk == n;
}
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < 2*n; i++)
    scanf("%d", a+i);
  sort(a, a+2*n);
  int sum = -1;
  for (int i = 0; i < 2*n-1; i++)
  {
    if (can(a[i] + a[2*n-1]))
    {
      sum = a[i] + a[2*n-1];
      break;
    }
  }
  if (sum != -1)
  {
    printf("YES\n");
    printf("%d\n", sum);
    for (auto i: ans)
      printf("%d %d\n", i.first, i.second);
  }else
  {
    printf("NO\n");
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
