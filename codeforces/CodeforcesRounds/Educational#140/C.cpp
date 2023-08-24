#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 2e5 + 9;
long long a[N], b[N];
int n;
long long extra[N];
long long can2(long long mn)
{
  for(int i = 0; i < n; i++)a[i] = b[i], extra[i] = 0;
  for(int i = n-1; i - 2 >= 0; i--)
  {
    long long cur = a[i];
    for(int j = 1; j <= 2; j++)
      if (i + j < n)
        cur += 1LL * j * extra[j + i];
    long long l = 0, r = cur / 3, m, d = 0;
    while(l <= r)
    {
      m = (l+r) >> 1LL; 
      if (cur - 3LL * m >= a[i-2] + 2 * m)
        d = m, l = m + 1;
      else 
        r = m - 1;
    }
    extra[i] = d; 
  }
  for(int i = 0; i < n; i++)cout << extra[i] <<" ";cout <<"\n";
  for(int i = 2; i < n; i++)
  {
    long long cur = a[i];
    for(int j = 1; j <= 2; j++)
      if (i + j < n)
        cur += 1LL * j * extra[j + i];
    long long l = 0, r = cur / 3, m, d = 0;
    while(l <= r)
    {
      m = (l+r) >> 1LL;
      if (3LL * m <= a[i] && cur - 3LL * m >= a[i-2] + 2LL * m)
        d = m, l = m + 1;
      else 
        r = m - 1;
    }
    a[i-2] += 2LL * d;
    a[i-1] += 1LL * d; 
    a[i] -= 3LL * d;
  }
  for(int i = 0; i < n; i++)cout << a[i] <<" ";cout <<"\n";
  long long ans = a[0];
  
  for(int i = 0; i < n; i++)
    ans = min(ans, a[i]);
  return ans;
}
bool can(long long mn)
{
  for(int i = 0; i < n; i++)a[i] = b[i], extra[i] = 0;
  for(int i = n-1; i - 2 >= 0; i--)
  {
    long long cur = a[i];
    for(int j = 1; j <= 2; j++)
      if (i + j < n)
        cur += 1LL * j * extra[j + i];
    long long l = 0, r = cur / 3, m, d = 0;
    while(l <= r)
    {
      m = (l+r) >> 1LL; 
      if (cur - 3LL * m >= mn)
        d = m, l = m + 1;
      else 
        r = m - 1;
    }
    extra[i] = d; 
  }
  for(int i = 2; i < n; i++)
  {
    long long cur = a[i];
    for(int j = 1; j <= 2; j++)
      if (i + j < n)
        cur += 1LL * j * extra[j + i];
    long long l = 0, r = cur / 3, m, d = 0;
    while(l <= r)
    {
      m = (l+r) >> 1LL;
      if (3LL * m > a[i])
      {
        r = m - 1;continue; 
      }
      if (cur - 3LL * m >= mn)
        d = m, l = m + 1;
      else 
        r = m - 1;
    }
    a[i-2] += 2LL * d;
    a[i-1] += 1LL * d; 
    a[i] -= 3LL * d;
  }
  //for(int i = 0; i < n; i++)cout << a[i] <<" ";cout <<"\n";
  for(int i = 0; i < n; i++)
    if (a[i] < mn)
      return 0;
  return 1;
}
void test()
{
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i < n; i++)
    scanf("%lld", a+i), b[i] = a[i], sum += a[i];
  printf("%lld\n", can2(1));
  return;
  long long l = 0, r = sum / n, m, ans = 0;
  while(l <= r)
  {
    m = (l+r) >> 1LL;
    if (can(m))
      ans = m, l = m + 1;
    else 
      r = m - 1;
  }
  printf("%lld\n", ans);
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
