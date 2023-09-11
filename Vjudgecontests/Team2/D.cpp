// Author : Mohamed Sameh
// created in: 10:54 PM
#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[55];
int frq[55][26];
void test(){
  memset(frq, 0, sizeof frq);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++){
    scanf(" %s", s);
    for (int j = 0; j < m; j++){
      frq[j][s[j] - 'a']++;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++){
    int mx = 0;
    for (int j = 0; j < 26; j++)
      if (frq[i][j] > frq[i][mx])
        mx = j;
    ans += frq[i][mx];
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