// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9;
int a[N], n, q;
long long pre[N];
long long sum(int l, int r)
{
  if (l > r)return -1;
  return pre[r] - (l-1>=0? pre[l-1]: 0);
}
int getpos(int left, int right, int val)
{
  int idx = left;
  while(left <= right)
  {
    int mid = (left + right) >> 1;
    if (a[mid] <= val)
      idx = mid + 1, left = mid+1;
    else
      right = mid - 1;
  }
  return idx;
}
map<long long, int> mp;
void solve(int l, int r)
{
  if (l > r)return;
  int mid = (a[l] + a[r]) >> 1;
  int nl = getpos(l, r, mid);
  long long sum1 = sum(l, nl-1);
  long long sum2 = sum(nl, r);
  mp[sum1] = mp[sum2] = 1;
  if (nl != l)
   solve(nl, r);
  if (nl-1 != r)
   solve(l, nl-1);
}
void test()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i-1] + a[i];
  }
  mp.clear();
  mp[pre[n-1]] = 1;
  solve(0, n-1);
  while(q--)
  {
    int need;
    scanf("%d", &need);
    if (mp.find(need) != mp.end())
      printf("Yes\n");
    else
      printf("No\n");
  }
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
