#include<bits/stdc++.h>
using namespace std;
int nxt[28][28];
int n, k;
bool better(int u, int v)
{
  int mn = nxt[u][0];
  int mn1 = nxt[v][0];
  for (int i = 0; i < k; i++)
  {
    mn = min(mn, nxt[u][i]);
    mn1 = min(mn1, nxt[v][i]);
  }
  return mn < mn1;
}
int main()
{
  scanf("%d%d", &n, &k);
  int lst = 27;
  for (int i = 0; i < n; i++)
  {
    int cur = 0;
    for (int j = 0; j < k; j++)
      if (nxt[lst][cur] > nxt[lst][j] || (nxt[lst][cur] == nxt[lst][j] && better(j, cur)))
        cur = j;
    printf("%c", cur + 'a');
    nxt[lst][cur]++;
    lst = cur;
  }
  printf("\n");
}
