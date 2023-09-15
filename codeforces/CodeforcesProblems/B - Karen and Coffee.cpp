// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int a[N], n, k, q;
int main()
{
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 0; i < n; i++)
  {
    int l, r;scanf("%d%d", &l, &r);
    a[l]++;
    a[r+1]--;
  }
 
  for (int i = 1; i < N; i++)
    a[i] += a[i-1];
 
  a[0] = (a[0] >= k? 1: 0);
  for (int i = 1; i < N; i++)
    a[i] = (a[i] >= k? 1: 0) + a[i-1];
 
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r] - a[l-1]);
  }
}
