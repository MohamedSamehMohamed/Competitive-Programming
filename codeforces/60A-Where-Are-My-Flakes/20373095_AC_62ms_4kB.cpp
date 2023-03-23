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
  int n , mi ;
  scanf ("%d%d" , &n ,&mi );
  int l = 1 , r = n ;
  for (int i =0 ; i < mi ; i++)
  {
    string x , t ;
    int v ;
    cin >> x >> x >> x >> t >> v ;
    if (x == "left")
    {
      r = min ( v-1  , r );
    }else
    {
      l = max ( v + 1 , l ) ;
    }
    if (l > r || l < 1 || r > n )
    {
      cout << "-1\n";
      return 0;
    }
  }
  cout << r - l + 1 <<"\n";

//cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
