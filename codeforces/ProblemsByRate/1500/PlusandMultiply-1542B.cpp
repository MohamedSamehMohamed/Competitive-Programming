#include <bits/stdc++.h>
using namespace std;
int n, a, b;
void test(){
  scanf("%d%d%d", &n, &a, &b);
  long long cur = 1;
  bool found = 0;
  while (cur <= n){
    if (cur == n || (n-cur) % b == 0){
      found = 1;
      break;
    }
    cur *= a;
    if (a == 1) break;
  }
  if (found)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}