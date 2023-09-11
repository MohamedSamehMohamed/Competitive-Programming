// Author : Mohamed Sameh
// created in: 8:37 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
char s[N];
string best = "-1";
bool solve(string x){
  int open = 0;
  bool good = 1;
  for (int i = 0; i < x.size(); i++){
    if (x[i] == '(')open++;
    else if (open > 0)open--;
    else good = 0;
  }
  if (open == 0 && good){
    if (best== "-1" || best.size() > x.size())
      best = x;
    return 1;
  }
  if (x.size() > 10) return 0;
  string ch = "()";
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      if (solve(ch[i] + x + ch[j])) continue;
    }
  }
  return 0;
}
void test(){
  scanf(" %s", s);
  int n = strlen(s);
  int open = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '(')open++;
    else if (open > 0){
      open--;
    }
  }
  int closed = 0;
  for (int i = n-1; i >= 0; i--){
    if (s[i] == ')')
      closed++;
    else if (closed > 0)
      closed--;
  }
  if ((open + closed) % 2 == 0){
    printf("%d\n", (open+closed) - min(open, closed) );
  }else
    printf("-1\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}