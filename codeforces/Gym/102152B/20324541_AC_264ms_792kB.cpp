// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf("%d" , &n )
void fo (){fflush(stdout);}
using namespace std;
ll fact (int x ){return (x <= 1 ? 1 : 1LL * x * fact (x-1));}
int a[100005];
int b[100005];
int main ()
{
  int t ;
  scanf ("%d" ,&t );
  while (t--)
  {
    memset (a , 0 , sizeof a );
    memset (b , -1 , sizeof b );

    int n , m , q;
    scanf ("%d%d%d" , &n ,&m ,&q );
    for (int i=0 ;i < n ;i++)
    {
      int l , r ;
      scanf ("%d%d" , &l ,&r );
      a[l]++;
      a[r+1]--;
    }
    for (int i =1 ; i <= m ;i++)
    a[i] += a[i-1];
    for (int i =m ; i > 0 ;i--)
    {
      if (a[i])continue ;
      int j = i-1 ;
      int len = 1;
      if (b[len] == -1 )
      b[len] = i ;
      while (j > 0 && !a[j])
      {
        len++;
        if (b[len] == -1 )
        b[len] = i;
        j--;
      }
      i = j + 1 ; 
    }

    while (q--)
    {
      int k ;
      scanf ("%d" , &k );
      if (b[k] != -1 )
      {
        printf ("%d %d\n" , b[k] - k + 1  , b[k]  );
      }else
      printf ("-1 -1\n");
    }
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
