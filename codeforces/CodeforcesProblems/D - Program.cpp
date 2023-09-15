// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int n, m, a[N], pre[N][2], suf[N][2];
void test()
{
  scanf("%d%d", &n, &m);
  suf[n+1][0] = suf[n+1][1] = pre[0][0] = pre[0][1] = a[0] = 0;
  string str = "";
  for (int i = 0; i < n; i++)
  {
    char c;
    scanf(" %c", &c);
    str += c;
    a[i+1] = a[i] + (c == '+'? 1: -1);
    pre[i+1][0] = max(pre[i][0], a[i+1]);
    pre[i+1][1] = min(pre[i][1], a[i+1]);
  }
  int sumMx = 0, sumMn = 0;
  for (int i = n-1; ~i; i--)
  {
    if (str[i] == '+')
      sumMx++, sumMn++;
    else
      sumMx--, sumMn--;
    sumMn = min(0, sumMn);
    sumMx = max(0, sumMx);
    suf[i+1][0] = sumMx;
    suf[i+1][1] = sumMn;
  }
  while(m--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    int mx = max(pre[l-1][0], suf[r+1][0] + a[l-1]);
    int mn = min(pre[l-1][1], suf[r+1][1] + a[l-1]);
    printf("%d\n", mx-mn+1);
  }
 
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
