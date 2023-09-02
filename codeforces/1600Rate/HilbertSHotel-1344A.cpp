// Author : Mohamed Sameh
// created in: 3:02 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, c[N];
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    c[i] = 0;
  }
  for (int i = 0; i < n; i++){
    int shift;
    scanf("%d", &shift);
    shift %= n;
    c[(i + shift + n) % n] += 1;
  }
  bool ok = 1;
  for (int i = 0; i < n; i++)
    ok &= (c[i] == 1);
  printf("%s\n", (ok? "YES": "NO"));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}