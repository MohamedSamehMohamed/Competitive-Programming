#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
char s[N];
void test(){
  scanf("%d %s", &n, s);
  int open = 0;
  for (int i = 0; i < n; i++)
    open += (s[i] == '(');
  if (n % 2 || open != n / 2)
  {
    printf("-1\n");
    return;
  }
  open = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '('){
      s[i] = '+';
      open++;
    }else if (open){
      s[i] = '-';
      open--;
    }
  }
  int cnt = 1;
  for (int i = n-1; i >= 0 && open > 0; i--){
    if (s[i] == '+')
    {
      open--;
      s[i] = '(';
    }
  }
  for (int i = 0; i < n; i++)
    if (s[i] != '+' && s[i] != '-'){
      cnt++;
      break;
    }
  for (int i = 0; i < n; i++){
    if (s[i] == '+' || s[i] == '-')
      break;
    if (i + 1 == n){
      cnt = 1;
    }
  }
  if (cnt == 2){
    // try to reverse all string 
    open = 0;
    for (int i = 0; i < n; i++){
      if (s[i] == '-' || s[i] == ')')
        open++;
      else if (open)
        open--;
      else {
        open = -1;
        break;
      }
    }
    if (open == 0)
      cnt = 1;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++){
    if (s[i] == '+' || s[i] == '-')
      printf("%d ", max(1, cnt-1));
    else 
      printf("%d ", cnt);
  }
  printf("\n");
  
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}