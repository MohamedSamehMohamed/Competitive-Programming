// Author : Mohamed Sameh
// created in: 4:33 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  long long mx = -1;
  for (int i = 0; i < n; i++){
    a[i]++;
    long long prd = 1;
    for (int j = 0; j < n; j++)
      prd *= a[j];
    if (mx == -1)
      mx = prd;
    if (prd > mx)
      mx = prd;
    a[i]--;
  }
  printf("%lld\n", mx);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}