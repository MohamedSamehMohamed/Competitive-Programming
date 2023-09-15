// Author : Mohamed Sameh
// created in: 7:03 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5002;
char a[N], b[N];
// 0 101 [01] 101 1 -> 0000011111
void test(){
  scanf(" %s %s", a, b);
  int n = strlen(a);
  for (int i = 0; i < n-1; i++){
    if (a[i] == '0' && b[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1'){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}