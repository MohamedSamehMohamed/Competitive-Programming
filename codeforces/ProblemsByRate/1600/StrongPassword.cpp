#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
char s[N], low[10], high[10];
int n, m;
int dp[N][10][2];
int nxtPos[N][10];
int getFirst(int start, char target){
  if (start == n) return n;
  if (s[start] == target) return start;
  return nxtPos[start][target - '0'];
}
int solve(int index = 0, int i = 0, bool same = 0){
  if (i == m){
    return !same;
  }
  int& ret = dp[index][i][same];
  if (~ret) return ret;
  ret = 0;
  for(char l = low[i]; !ret && l <= high[i]; l++){
    int nxt = getFirst(index, l);
    if (nxt == n){
      ret = 1;
      break;
    }else 
      ret = solve(nxt + 1, i + 1, 1);
  }
  return ret;
}
void test(){
  scanf(" %s", s);
  n = strlen(s);
  scanf("%d", &m);
  scanf(" %s %s", low, high);
  
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 10; j++)
      dp[i][j][0] = dp[i][j][1] = -1;

  for (int i = 0; i < 10; i++)
    nxtPos[n-1][i] = n;
  
  for (int i = n-2; i >= 0; i--){
    for (int j = 0; j < 10; j++)
      nxtPos[i][j] = nxtPos[i+1][j];
    nxtPos[i][s[i+1] - '0'] = i + 1;
  }
  
  printf("%s\n", (solve()? "YES": "NO"));
}
int main(){
  int t;scanf("%d", &t);
  while (t--)
    test();
}