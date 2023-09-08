// Author : Mohamed Sameh
// created in: 6:17 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, a[N];
void read(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
}
void test(){
  read();
  sort(a + 2, a + n);
  int ans = 2e9;
  for (int i = 2; i + m <= n; i++){
    ans = min(ans, max(0, a[0] - a[i]) + max(0, a[i+m-1] - a[1]));
  }
  printf("%d\n", ans);
}
int main(){
  test();
}