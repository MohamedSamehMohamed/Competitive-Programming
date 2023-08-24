#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 9;
int a[N], n;
bool exist[N];
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    exist[a[i]] = 0;
  }
  for (int i = 0; i < n; i++){
    int sum = a[i];
    for (int j = i + 1; j < n; j++){
      sum += a[j];
      if (sum >= N) break;
      exist[sum] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    cnt += exist[a[i]];
  }
  printf("%d\n", cnt);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}