#include<bits/stdc++.h>
using namespace std;
int n, m;
void test(){
  scanf("%d%d", &n, &m);
  for (int i = n - (n%2==0); i >= 1; i-=2){
    for (int j = 1; j <= m; j++){
      printf("%d ", (i-1) * m + j);
    }
    printf("\n");
  }
  for (int i = n-(n%2); i >= 1; i-=2){
    for (int j = 1; j <= m; j++){
      printf("%d ", (i-1) * m + j);
    }
    printf("\n");
  }
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}