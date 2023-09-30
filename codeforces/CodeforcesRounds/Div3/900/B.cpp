// Author : Mohamed Sameh
// created in: 4:35 PM
#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  vector<int> a(n);
  a[0] = 1;
  a[1] = 3;

  for (int i = 2; i < n; i++){
    a[i] = a[i-1] + 1;
    if ((a[i-1] + a[i]) % 3 == 0)
      a[i]++;
    while ((3LL * a[i]) % (a[i-1] + a[i-2]) == 0)
      a[i]++;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}