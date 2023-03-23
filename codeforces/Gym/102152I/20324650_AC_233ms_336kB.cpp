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
int a[10000];
int main ()
{
  int t ;
  scanf ("%d" ,&t );
  while (t--)
  {
    int n , k ;
    scanf ("%d%d" ,&n , &k  );
    vector <int> a ,b ;
    int zz =0 ;
    for (int i =0 ; i < n ;i++)
    {
      int val ;
      scanf ("%d" ,&val );
      if (val >= 0 )a.pb(val);
      else
      b.pb(val);
      if (val == 0 )zz = 1;
    }
    sort(all(a));
    sort(all(b));
    for (int i =0 ; i < SZ(b) && k ; i++, k--)
    {
      b[i] = -b[i];
    }
    if (zz )k =0 ;
    k%=2;
    sort(all(b));
    if (k)
    {
      if (SZ(a) && SZ(b))
      {
        if (a[0] > b[0] )
        b[0] = -b[0];
        else
        a[0] = -a[0];
      }else if (SZ(a))
      {
        a[0] = -a[0];
      }else
      {
        b[0] = -b[0];
      }
    }
    int sum =0;
    for (int i =0 ; i < SZ(a);i++)
    sum += a[i];
    for (int i =0 ; i < SZ(b) ;i++)
    sum += b[i];
    printf ("%d\n" ,sum );
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
