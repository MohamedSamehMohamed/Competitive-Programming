// Author : Mohamed Sameh
// created in: 4:21 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int s[N], e[N];
void test(){
  scanf("%d", &n);
  set<int> values;
  for (int i = 0; i < n; i++){
    scanf("%d%d", s+i, e+i);
    for (int j = -1; j <= 1; j++){
      int cur = s[i] + j;
      if (cur >= 1 && cur <= (int)1e9)
        values.insert(cur);
    }
  }
  int ans = -1;
  for (int v: values){
    int mx = 0;
    int cnt = 0;
    int winner = -1;
    for (int i = 0; i < n; i++){
      if (s[i] >= v){
        if (e[i] > mx){
          mx = e[i];
          cnt = 1;
          winner = i;
        }else if (e[i] == mx){
          cnt++;
        }
      }
    }
    if (winner == 0 && cnt == 1){
      if (ans == -1) ans = v;
      ans = min(ans, v);
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}