// Author : Mohamed Sameh
// created in: 4:52 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, k, a[N], h[N], good[N];
void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", h+i);
  good[0] = 1;
  for (int i = 1; i < n; i++){
    if (h[i-1] % h[i] == 0)
      good[i] = 1;
    else
      good[i] = 0;
    good[i] += good[i-1];
  }
  //for (int i = 0; i < n; i++) cout << good[i] <<" ";cout <<"\n";
  // stupid way
  int l = 1, r = n, m, mxLen = 0;
  while (l <= r){
    m = (l+r) >> 1;
    long long sum = 0;
    for (int i = 0; i < m-1; i++)
      sum += a[i];
    bool ok = 0;
    for (int i = 0, j = m-1; j < n; i++, j++){
      sum += a[j];
      //cout << i <<" " << j <<" " << sum <<" " << good[j] - (i-1>=0?good[i-1]:0) << " " << m <<"\n";
      if (good[j] - good[i] + 1 == m && sum <= k)
      {
        ok = 1;
        break;
      }
      sum -= a[i];
    }
    if (ok)
      mxLen = max(m,mxLen), l = m + 1;
    else
      r = m - 1;
  }
  printf("%d\n", mxLen);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}