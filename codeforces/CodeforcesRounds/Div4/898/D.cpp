// Author : Mohamed Sameh
// created in: 4:42 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, k;
char s[N];
void test(){
  scanf("%d%d %s", &n, &k, s);
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'B'){
      ans++;
      i += k - 1;
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}