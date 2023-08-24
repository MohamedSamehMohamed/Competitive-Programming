// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int a[N], b[N], n, m, k;
void test()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++)
    scanf("%d", a+i);
  for (int i = 0; i < k; i++)
    scanf("%d", b+i);
  map<int, int> aa, bb;
  long long ans = 0;
  for (int i = 0; i < k; i++)
  {
    ans += k-1;
    aa[a[i]]++;
    bb[b[i]]++;
  }
  for (int i = 0; i < k; i++)ans -= aa[a[i]]+bb[b[i]]-2;
  printf("%lld\n", ans>>1LL);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
