// Author : Mohamed Sameh
// created in: 6:05 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N], pos[N], n, k;
void test(){
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
    sum += a[i];
  }
  long long cur = (1LL * (n+1) * (n))/2LL;
  a[n] = cur - sum;
  for (int i = 0; i <= n; i++)
    pos[a[i]] = i;
  for (int i = 0; i < n; i++){
    int p = pos[a[i]];
    p -= k;
    p %= (n+1);
    p += (n+1);
    p %= (n+1);
    b[i] = a[p];
  }
//  for (int j = 0; j < k; j++) {
//    for (int i = 0; i < n; i++) {
//      long long nw = cur - sum;
//      sum -= a[i];
//      sum += nw;
//      a[i] = nw;
//    }
//  }
  for (int i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}