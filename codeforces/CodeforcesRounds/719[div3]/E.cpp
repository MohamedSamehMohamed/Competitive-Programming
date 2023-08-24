#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
char x[N];
int n;
long long Sum[N];
long long sum(int l, int r)
{
  long long R = (1LL * r * (r+1))/2;
  l--;
  if (l <= 0)return R;
  return R - (1LL * l * (l+1))/2;
}
long long prefix(int l, int r)
{
  return Sum[r] - Sum[l-1];
}
void test()
{
  scanf("%d", &n);
  scanf("%s", x+1);
  long long posSumSuf = 0, posSumPre = 0;
  int sheep = 0;
  Sum[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    Sum[i] = Sum[i-1];
    if (x[i] == '*')
    {
      sheep++;
      Sum[i] += i;
    }
  }
  if (sheep == 0 || sheep == n)
  {
    printf("0\n");
    return;
  }
  long long ans = 1e18;
  int before = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i + sheep - 1 > n)break;
    long long curSum = prefix(i+sheep, n) - sum(i, i + sheep - 1) + prefix(1, i-1);
    cout << prefix(i+sheep, n) << " " << sum(i, i+sheep-1) << " " << prefix(1, i-1) <<"\n";
    cout << curSum << " " << i <<"\n";
    long long curAns = 0;
    ans = min(curAns, ans);
    if (x[i] == '*')
    {
      posSumPre += i;
      posSumSuf -= i;
    }
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
