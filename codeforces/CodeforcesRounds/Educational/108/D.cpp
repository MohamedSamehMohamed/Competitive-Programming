#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
int a[N], b[N], n;
long long pre[N];
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 1; i <= n; i++)
    scanf("%d", b+i);
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i-1] + 1LL * a[i] * b[i];
  long long best = pre[n];
  for (int center = 1; center <= n; center++)
  {
    int l = center - 1, r = center + 1;
    long long curValue = 1LL * a[center] * b[center] + pre[center-1] + pre[n] - pre[center];
    while(l >= 1 && r <= n)
    {
      curValue -= 1LL * a[l] * b[l];
      curValue -= 1LL * a[r] * b[r];
      curValue += 1LL * a[r] * b[l];
      curValue += 1LL * a[l] * b[r];
      best = max(best, curValue);
      l--;
      r++;
    }
    l = center, r = center + 1;
    curValue = 1LL * a[center] * b[center] + pre[center-1] + pre[n] - pre[center];
    while(l >= 1 && r <= n)
    {
      curValue -= 1LL * a[l] * b[l];
      curValue -= 1LL * a[r] * b[r];
      curValue += 1LL * a[r] * b[l];
      curValue += 1LL * a[l] * b[r];
      best = max(best, curValue);
      l--;
      r++;
    }
  }
  printf("%lld\n", best);
}
