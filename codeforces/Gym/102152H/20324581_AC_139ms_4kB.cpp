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
int main ()
{
  int t ;
  scanf ("%d" ,&t );
  while (t--)
  {
    string x ;
    cin >> x;
    bool ok =1 ;
    for (int i =1 ; i < SZ(x) ;i++)
    {
      if (x[i-1] == 'z')
      {
        if (x[i] != 'a')
        {
          ok  =0 ;
          break;
        }
      }else
      {
        if (x[i-1] + 1 != x[i])
        {
          ok =0 ;
          break;
        }
      }
    }
    if (ok)
    printf ("YES\n");
    else
    printf ("NO\n");
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
