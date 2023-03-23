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
int main ()
{
  int n ;
  cin >> n ;
  int T , px , py ;
  T = px = py = 0 ;
  bool ok = 1;
  for (int i =0 ; i < n ;i++)
  {
    int t , x , y ;
    cin >> t >> x >> y ;
    int Time = t - T ;
    int steps = abs (x - px ) + abs (y - py );
    T = t ;
    px = x ;
    py = y ;
    if (steps > Time )
    {
      ok = 0;break;
    }else if (steps == Time )
    {
      continue ;
    }else
    {
      Time -= steps ;
      if (Time % 2 )
      {
        ok = 0 ;
        break;
      }
    }
  }
  if (ok)printf ("Yes\n");
  else
  printf ("No\n"); 
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
