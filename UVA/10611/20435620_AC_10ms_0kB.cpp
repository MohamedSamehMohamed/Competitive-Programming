// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}
using namespace std;
int a[50000];
int n , q ;
int main ()
{
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++)
  scanf ("%d" ,a+i );

  scanf ("%d" , &q );
  while (q--)
  {
    int vl ;
    scanf ("%d" , &vl );
    int l =0 , r = n-1 , m , ans = -1 ;
    while (l <= r )
    {
      m = (l+r)>>1;
      if (a[m] < vl )
      {
        ans = m ;
        l = m+1;
      }else
      r = m-1;
    }
    if (ans == -1 )printf ("X ");
    else
    printf ("%d " ,a[ans] );
    l =0 , r = n-1 , ans = -1 ;
    while (l <= r)
    {
      m = (l+r)>>1;
      if (a[m] > vl )
      {
        ans = m;
        r = m-1;
      }else
      l = m+1;
    }
    if (ans == -1 )printf ("X\n");
    else
    printf ("%d\n" ,a[ans] );

  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
