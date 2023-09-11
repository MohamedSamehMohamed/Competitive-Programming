// Author : Mohamed Sameh
// created in: 8:39 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int ans[N];
void prepare(){
  // 5   1,4  2,3 3,2  4,1
  // 4   1,3 2, 2, 3,1
  // 8   1,7 2,6, 3,5, 4,4 5,3 6,2, 7,1
  for (int i = 2; i < N; i++){
    for (int j = 2*i; j < N; j+=i)
      ans[j] += i;
  }
}
void test(){
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n]);
}
int main()
{
  prepare();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}