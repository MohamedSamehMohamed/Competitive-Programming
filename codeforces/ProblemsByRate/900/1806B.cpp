// Author : Mohamed Sameh
// created in: 1:35 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
int frq[N], n;
void test(){
  scanf("%d", &n);
  memset(frq, 0, sizeof frq);
  for (int i = 0; i < n; i++){
    int x;scanf("%d", &x);
    frq[x]++;
  }
  if (frq[0] == 0 || n - frq[0] >= frq[0] - 1){
    printf("0\n");
    return;
  }
  for (int i = 1; i < N; i++){
    if (frq[i] == 0 || n - frq[i] - frq[0] > 0){
      printf("%d\n", i);
      return;
    }
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}