#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n;
long long pre[N], a[N];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  pre[0] = a[0];
  for (int i = 1; i < n; i++)pre[i] = pre[i-1] + a[i];
  for (int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    a[i] -= x;
  }
  long long mx = -1e18;
  int sz = 0;
  map<long long, int> mp;
  mp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      int cursz = 1;
      long long cursum = pre[i] - (i-1>=0? pre[i-1]: 0);
      if (cursum > mx || (cursum == mx && cursz > sz))
       mx = cursum, sz = cursz;
      continue;
    }
    if (mp.find(-a[i]) != mp.end())
    {
     int j = mp[-a[i]];
     int cursz = i - j + 1;
     long long cursum = pre[i] - (j-1>=0? pre[j-1]: 0);
     if (cursum > mx || (cursum == mx && cursz > sz))
      mx = cursum, sz = cursz;
    }
    if (mp.find(a[i]) == mp.end())mp[a[i]] = i;
  }
  if (sz == 0)
  {
    printf("-1\n");
    return 0;
  }
  printf("%lld %d\n", mx, sz);
}
