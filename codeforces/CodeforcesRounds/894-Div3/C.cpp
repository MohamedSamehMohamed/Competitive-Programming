// Author : Mohamed Sameh
// created in: 4:52 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int cur = 0;
  int r = n-1;
  while (cur < n){
    while (r >= 0 && a[r] < cur + 1)
      r--;
    if (r + 1 != a[cur]){
      break;
    }
    cur++;
  }
  if (cur == n)
    printf("YES\n");
  else
    printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}