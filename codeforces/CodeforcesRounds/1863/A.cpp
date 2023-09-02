// Author : Mohamed Sameh
// created in: 4:31 PM
#include <bits/stdc++.h>
using namespace std;
int n, a, q;
char s[101];
void test(){
  scanf("%d%d%d %s", &n, &a, &q, s);
  if (n == a)
  {
    printf("YES\n");
    return;
  }
  int mx = a;
  int in = a;
  int out = n - a;
  int read = a;
  int cur = a;
  for (int i = 0; i < q; i++){
    if (s[i] == '+'){
      cur++;
      if (out > 0){
        out--;
        in++;
        read++;
      }
    }else {
      cur--;
      if (in > 0){
        in--;
      }
    }
    if (cur == n){
      printf("YES\n");
      return;
    }
    mx = max(mx, read);
  }
  if (mx == n)
    printf("MAYBE\n");
  else{
    printf("NO\n");
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}