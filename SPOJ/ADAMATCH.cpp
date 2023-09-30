// Author : Mohamed Sameh
// created in: 7:52 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
char s[N];
string a, b;
int pre[N][4][4];
int me[4][4];
unordered_map<char, int> mp;
string read(){
  scanf(" %s", s);
  return s;
}
void test(){
  mp['A'] = 0;
  mp['C'] = 1;
  mp['T'] = 2;
  mp['G'] = 3;
  a = read(), b = read();
  int n = a.size(), m = b.size();
  if (m == 1){
    if (a.find(b[0]) < a.size())
      printf("0\n");
    else
      printf("1\n");
    return;
  }
  for (int i = 1; i < m; i++)
    me[mp[b[i-1]]][mp[b[i]]]++;
  for (int i = 1; i <= n; i++){
    int u = mp[a[i-1]], v = mp[a[i]];
    pre[i][u][v]++;
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        pre[i][j][k] += pre[i-1][j][k];
  }
  int ans = m;
  for (int i = 1, j = m; j <= n; i++, j++){
    int dif = 0;
    for (int u = 0; u < 4; u++)
    {
      bool exist = 0;
      for (int v = 0; v < 4; v++){
        int cur = pre[j-1][u][v] - pre[i-1][u][v];
        if (cur == me[u][v]){
          exist = 1;
          break;
        }
      }
      if (exist) continue;
    }
    ans = min(ans, dif);
  }
  printf("%d\n", ans);

}
int main()
{
  test();
}