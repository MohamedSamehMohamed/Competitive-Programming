// Author : Mohamed Sameh
// created in: 8:50 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], c[N], n, k, sufMin[N];
int tt;
void test(){
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) a[i] = 0;

  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  scanf("%d", &k);

  sufMin[n-1] = n - 1;
  for (int i = n-2; i >= 0; i--){
    sufMin[i] = (c[sufMin[i+1]] <= c[i+1]? sufMin[i+1]: i + 1);
  }
  int idx = (c[0] < c[sufMin[0]]? 0: sufMin[0]);
  while (k > 0){
    int add = k / c[idx];
    if (add < 1) break;
    if (idx == n-1){
      a[0]+=add;
      a[idx+1]-=add;
      break;
    }
    int l = 0, r = add, m, take = add;
    while (l <= r){
      m = (l+r) >> 1;
      long long rem = 1LL * k - 1LL * m * c[idx];
      if (1LL * (add-m) * c[sufMin[idx]] <= rem){
        take = m;
        r = m - 1;
      }else
        l = m + 1;
    }
    int rem = k - take * c[idx];
    a[0]+=take;
    a[idx+1]-=take;
    k = rem;
    if (take != add){
      idx = sufMin[idx];
    }
  }
  for (int i = 0; i < n; i++)
  {
    a[i] += (i? a[i-1]: 0);
    printf("%d ", a[i]);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}