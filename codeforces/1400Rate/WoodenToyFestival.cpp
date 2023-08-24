#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a + n);
  int l = 0, r = 1e9, m, ans = 1e9;
  while (l <= r){
    m = (l+r) >> 1;
    int i = 1, j = n - 2;
    while (i < n && a[i] - a[0] <= 2 * m)
      i++;
    i--;
    while (j > i && a[n-1] - a[j] <= 2 * m)
      j--;
    j++;
    i++;
    j--;
    if (i > j || a[j] - a[i] <= 2 * m)
      ans = m, r = m - 1;
    else 
      l = m + 1;
  }  
  printf("%d\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}