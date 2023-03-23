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

  string x ;
  ll ans =0 ;
  int per =0 ;
  while (getline(cin , x ))
  {
    if (x[0] == '+')
    per++;
    else if (x[0] == '-')
    per--;
    else
    {
      for (int i =0 ; i < SZ(x) ;i++)
      {
        if (x[i] == ':')
        {
          ans += 1LL * per * (SZ(x) - i - 1 );
          break;
        }
      }
    }
  }
  cout << ans <<"\n";

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
