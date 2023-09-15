// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int n, a[N];
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  vector<int> v;
  v.push_back(a[0]);
  for (int i = 1; i < n; i++)
  {
    if (a[i] == v.back())continue;
    v.push_back(a[i]);
  }
 
  map<int,int> mp;
  for (int i = 0; i < v.size(); i++)
  {
    mp[v[i]]++;
  }
  int ret = n;
  for (int i = 0; i < v.size(); i++)
  {
    if (mp[v[i]] == 1)
    {
      if (i == 0 || i == v.size()-1)
        ret = min(ret,1*(v.size() > 1));
      else
        ret = min(ret, 2);
    }else if (mp[v[i]] == 2 && v[i] == v[0] && v[i] == v.back())
    {
      ret = 1;
    }else
    {
      int cursol = mp[v[i]] - 1;
      if (v[0] != v[i])cursol++;
      if (v.back() != v[i])cursol++;
      ret = min(ret, cursol);
    }
  }
  printf("%d\n", ret);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    test();
  }
}
