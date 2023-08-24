#include<bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  if (n <= 2){
    for (int i = 1; i <= n; i++)
      printf("%d ", i);
    printf("\n");
    return;
  }
  printf("2 ");
  for (int i = 4; i <= n; i++){
    if ((i-2) == (n+1) / 2)
      printf("1 ");
    printf("%d ", i);
  }
  if (n == 3) printf("1 ");
  printf("3\n");
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}