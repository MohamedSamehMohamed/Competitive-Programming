// Author : Mohamed Sameh
// created in: 4:52 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, k, a[N], h[N];
void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", h+i);
  int mxLen = 0;
  for (int i = 0; i < n; i++)
    if (a[i] <= k)
      mxLen = 1;
  int l = 0, r = 1;
  long long cnt = a[0];
  while (r < n){
    while (r < n && cnt + a[r] <= k && h[r-1] % h[r] == 0){
      cnt += a[r];
      r++;
    }
    if (cnt <= k)
      mxLen = max(mxLen, r - l);
    cnt -= a[l];
    l++;
    if (l == r && r < n){
      cnt += a[l];
      r++;
    }
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