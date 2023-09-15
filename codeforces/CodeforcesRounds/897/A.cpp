// Author : Mohamed Sameh
// created in: 4:24 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 9;
int a[N], ord[N], out[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  iota(ord, ord + n, 0);
  sort(ord, ord + n, [](int i, int j){
    return a[i] < a[j];
  });
  for (int i = 0; i < n; i++){
    out[ord[i]] = n - i;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", out[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}