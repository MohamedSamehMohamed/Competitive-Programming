// Author : Mohamed Sameh
// created in: 6:14 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, a[N], pre[N];
char s[N];
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
  }

  scanf(" %s", s);
  pre[0] = 0;
  int zeroXor = 0;
  for (int i = 1; i <= n; i++){
    pre[i] = pre[i-1] ^ a[i-1];
    if (s[i-1] == '0')
      zeroXor ^= a[i-1];
  }
  int q;
  scanf("%d", &q);
  while (q--){
    int ty, l, r;scanf("%d", &ty);
    if (ty == 1){
      scanf("%d%d", &l, &r);
      int range = pre[r] ^ pre[l-1];
      zeroXor ^= range;
    }else {
      scanf("%d", &l);
      if (l == 1){
        printf("%d ", pre[n] ^ zeroXor);
      }else {
        printf("%d ", zeroXor);
      }
    }
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