#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, c, t1, t2;
int a[1001];
int dist(int v, int u)
{
  if (v >= u) return v - u;
  // cout << v <<" " << u <<" " << v + (c-u) <<"\n";
  return c - u + v;
}
int solve(int st)
{
  int cur = 0;
  for (int i = st; ; i = (i+1) % n)
  {
    int j = i+1;
    while(j != st && dist(a[j], a[i]) <= t2)
      j = (j + 1) % n;
    j = (j - 1 + n) % n;
    cur += (dist(a[j], a[i]) <= t1? t1: t2);
    if ((j+1)%n == st)
      break;
    i = j; 
  }
  return cur;
}
void test()
{
  scanf("%d%d%d%d", &n, &c, &t1, &t2);
  if (t1 > t2)swap(t1, t2);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int ans = 1e9;
  for (int i = 0; i < n; i++)
    ans = min(ans, solve(i));
  printf("%d\n", ans);
}
int main()
{
  read_file();
  test();
}
