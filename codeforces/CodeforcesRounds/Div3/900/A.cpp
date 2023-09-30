// Author : Mohamed Sameh
// created in: 4:29 PM
#include <bits/stdc++.h>
using namespace std;
int n, k;
void test(){
  scanf("%d%d", &n, &k);
  bool ok = 0;
  for (int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    ok |= (x == k);
  }
  if (ok)
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