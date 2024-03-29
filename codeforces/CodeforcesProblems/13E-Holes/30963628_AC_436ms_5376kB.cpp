// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e5+ 1  ;
int par[N], Njums[N], a[N],block[N], n, q, sq ;
void Fix (int idx )
{
  if (idx + a[idx] > n)
  {
    par[idx] = idx ;
    Njums[idx]=1;
    return ;
  }
  int next = idx + a[idx];
  int moves =1 ;
  while (next <= n && block[next] == block[idx] && par[next] != next)
  {
    moves += Njums[next];
    next = par[next];
  }
  par[idx] = next ;
  Njums[idx] = moves ;
}
void update (int idx, int val)
{
  a[idx] = val;
  int same = idx - 1;
  Fix(idx);
  while (same >= 1 && block[same] == block[idx])
  {
    if (same + a[same] > n || block[same + a[same]] != block[same] || par[same] == same )
    {
      same--;
      continue ;
    }
    Njums[same] = 1 + (par[same + a[same]] == same + a[same] ? 0 : Njums[same + a[same]]);
    par[same] = par[same + a[same]];
    same--;
  }
}
void debug ()
{
  printf ("*********\n");
  for (int i = 1; i <= n ;i++)
  printf ("%d ", a[i]);
  printf ("\n");
  for (int i = 1; i <= n ;i++)
  printf ("%d %d %d\n" , block[i] , par[i] , Njums[i]);
  printf ("***********\n");
}
int main()
{
    scanf("%d%d", &n, &q);
    sq = sqrt(n);
    for (int i =1 ;i <= n ;i++)
    {
      scanf("%d", a+i);
      par[i] = -1;
      block[i] = i/ sq ;
    }
    for (int i =n; i >= 1 ;i--)
    {
        if (i + a[i] > n )
        {
          par[i] = i ;
          Njums[i] = 1 ;
          continue ;
        }
        int next = i + a[i];
        int jN =1 ;
        while (next <= n && block[next] == block[i] && next + a[next] <= n){jN++;next+=a[next];}
        par[i] = next ;
        Njums[i] = jN ;
    }
    while (q--)
    {
      int ty, x, y ;
      scanf("%d", &ty);
      if (ty == 0 )
      {
        scanf("%d%d", &x, &y);
        update(x, y);
      }else
      {
          scanf("%d", &x );
          int ans = (x == par[x] ? 0 :Njums[x]);
          x = par[x];
          while (x != par[x])
          {
            ans += Njums[x];
            x = par[x];
          }
          ans += Njums[x];
          printf("%d %d\n", x , ans );
      }
      //debug();
    }
}