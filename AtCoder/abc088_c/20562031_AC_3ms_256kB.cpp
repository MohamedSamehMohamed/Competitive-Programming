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
int a[3][3];
int A[3] , B[3];
bool check ()
{
  for (int i =0 ; i < 3; i++)
  {
    for (int j =0 ; j < 3; j++)
    {
      if (a[i][j] != A[i] + B[j])
      return false;
    }
  }
  return true ;
}
int main ()
{
  for (int i =0 ; i < 3 ;i++)for (int j =0 ; j < 3 ;j++)cin >>a[i][j];
  for (int a1 = 0 ; a1 <= 100 ; a1++)
  {
    for (int a2 = 0 ; a2 <= 100 ; a2++)
    {
      for (int a3 = 0 ; a3 <= 100 ;a3++)
      {
        B[0] = a[0][0] - a1 ;
        B[1] = a[1][1] - a2 ;
        B[2] = a[2][2] - a3 ;
        A[0] = a1 ;
        A[1] = a2 ;
        A[2] = a3 ;
        if ( check() )
        {
          cout <<"Yes\n";
          return 0 ;
        }

      }
    }
  }
  cout <<"No\n"; 

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
