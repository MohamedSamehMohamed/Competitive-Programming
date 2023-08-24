#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
int suf[N][31];
void init(){
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < 31; j++)
      suf[i][j] = 0;
  }
}
bool isSet(int num, int p){
  if ((num & (1LL << p)))
    return 1;
  return 0;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int gCount = 0;
  init();
  for (int i = n-1; i >= 0; i--){
    for (int j = 0; j < 31; j++){
      if (isSet(a[i], j)){
        suf[i][j] = 0;
      }else {
        suf[i][j] = 1;
      }
      if (i + 1 < n)
        suf[i][j] += suf[i+1][j];
    }
  }
  
  for (int i = 0; i < n; i++){
    int cur = a[i];
    int j = i + 1;
    while (j < n){
      bool take = 0;
      for (int k = 0; k < 31; k++){
        if (isSet(cur, k)){
          if (suf[j][k]){
            take = 1;
            break;
          }
        }else {
          if (suf[j][k] == 0){
            take = 1;
            break;
          }
        }
      }
      if (!take){
        for (int k = 0; k < 31; k++){
          if (suf[j][k] == 0){
            take = 1;
            break;
          }
        }
        if (!take) break;
      }
      cur &= a[j];
      j++;
    }
    i = j - 1;
    gCount++;
  }
  printf("%d\n", gCount);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}

