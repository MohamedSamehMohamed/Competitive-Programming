// Author : Mohamed Sameh
// created in: 1:07 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char s[N];
int state[N];
void test(){
  scanf(" %s", s);
  int n = strlen(s);
  memset(state, -1, sizeof(state[0]) * (n + 1));
  bool valid = 1;
  int sz = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '+'){
      sz++;
      if (state[sz-1] == 0)
        state[sz] = 0;
      continue;
    }else if (s[i] == '-'){
      sz--;
      if (state[sz+1] == 1)
        state[sz] = 1;
      state[sz+1] = -1;
      continue;
    }
    if (s[i] == '0'){
      if (state[sz] == 1 || sz <= 1){
        valid = 0;
        break;
      }
      state[sz] = 0;
    }else {
      if (state[sz] == 0){
        valid = 0;
        break;
      }
      state[sz] = 1;
    }
  }
  if (valid)
    printf("YES\n");
  else
    printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}