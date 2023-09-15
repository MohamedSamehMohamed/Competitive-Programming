#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, q;
int a[N], pre[N];
void test(){
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  memset(pre, 0, sizeof pre[0] * n);
  for (int i = 1; i < n - 1; i++){
    pre[i] = pre[i-1] + (a[i-1] >= a[i] && a[i] >= a[i+1]);
  }
  for (int i = 0; i < q; i++){
    int l, r;
    scanf("%d%d", &l, &r);
    l--;r--;
    if (l == r)
      printf("1\n");
    else 
      printf("%d\n", (r-l+1) - pre[r-1] + pre[l]);
  }
}
int main(){
  test();
}