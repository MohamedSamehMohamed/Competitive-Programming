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
int n , ans [100000] , ps[][2] = {{1,1} , {1,0} , {0,1} , {0,0}};
string x ;
bool check ()
{
  for (int i =0 ; i < n ;i++)
  {
    int prv = (i - 1 + n )%n ;
    int nex = (i + 1 )%n ;

    if (ans[i] == 1 )
    {
      if (x[i] == 'o')
      {
        if (ans[prv] != ans[nex])return false ;
      }else
      {
        if (ans[prv] == ans[nex])return false ;
      }
    }else
    {
      if (x[i] == 'o')
      {
        if (ans[prv] == ans[nex])return false ;
      }else
      {
        if (ans[prv] != ans[nex])return false ;
      }

    }
  }
  return true ;
}
int main ()
{
cin >> n >> x ;
for (int p =0 ; p < 4 ; p++)
{
  ans[0] = ps[p][0];
  ans[1] = ps[p][1];
  for (int i = 1 ; i < n ;i++)
  {
    // 1 S
    // 0 W
    int prv = (i -1 + n )% n ;
    int nex = (i + 1 )%n ;
    if (ans[i] == 1 )
    {
      if (x[i] == 'o')
      {
      ans[nex] = ans[prv] ;
      }else
      {
      ans[nex] = abs (ans[prv] - 1);
      }

    }else
    {
      if (x[i] == 'o')
      {
        ans[nex] = abs (ans[prv] - 1);
      }else
      {
        ans[nex] = ans[prv] ;
      }
    }
  }
  if (check())
  {
    for (int i =0 ; i < n ;i++)
    if (ans[i])printf ("S");
    else
    printf("W");
    printf("\n");
    return 0 ;
  }
}
printf("-1\n");
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
