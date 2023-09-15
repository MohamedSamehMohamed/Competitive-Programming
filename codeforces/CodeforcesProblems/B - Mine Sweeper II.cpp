// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e3 + 9;
int n, m, mx, dif;
bool a[N][N], b[N][N];
int main()
{
  scanf("%d%d", &n, &m);
  mx = (n*m)>>1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
      char c;scanf(" %c", &c);a[i][j] = (c == 'X'? 1: 0);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
      char c;scanf(" %c", &c);b[i][j] = (c == 'X'? 1: 0);
      dif += (a[i][j] != b[i][j]);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      printf("%c%s", (a[i][j]? (dif>mx?'.':'X'): (dif>mx?'X':'.')),(j+1<m?"": "\n"));
 
}
