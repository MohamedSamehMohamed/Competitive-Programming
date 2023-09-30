// Author : Mohamed Sameh
// created in: 4:42 PM
#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  int mnR = 1e9 + 1;
  int mnC = 1e9 + 1;
  long long sumR = 0, sumC = 0;
  for (int i = 0; i < n; i++){
    int r;
    scanf("%d", &r);
    mnR = min(r, mnR);
    sumR += r;
  }
  for (int i = 0; i < n; i++){
    int r;
    scanf("%d", &r);
    mnC = min(r, mnC);
    sumC += r;
  }
  printf("%lld\n", min(sumR + 1LL * n * mnC, sumC + 1LL * n * mnR));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}