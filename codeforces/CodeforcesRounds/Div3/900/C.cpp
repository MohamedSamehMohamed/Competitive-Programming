// Author : Mohamed Sameh
// created in: 4:43 PM
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long x;
long long sum(long long num){
  return (num * (num+1)) / 2;
}
void test(){
  scanf("%d%d%lld", &n, &k, &x);
  long long mnSum = sum(k);
  long long mxSum = sum(n) - sum(n-k);
  if (x < mnSum || x > mxSum)
    printf("No\n");
  else
    printf("Yes\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}