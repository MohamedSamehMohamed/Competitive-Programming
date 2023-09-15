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
string x , y , z ;
cin >> x >> y >> z ;
bool fo , ba ;
fo = ba = 0;
for (int i =0 ; i + SZ(y)<= SZ(x) ;i++)
{
  if (x.substr(i,SZ(y)) == y )
  {
    bool ok = 0;
    i += SZ(y);
    while (i + SZ(z) <= SZ(x))
    {
      if (x.substr(i , SZ(z)) == z)
      {
        ok = 1;
        break;
      }
      i++;
    }
    if (ok)fo = 1;
  }
}
for (int i =0 , j = SZ(x)-1 ; i < j ; i++,j--)swap(x[i] ,x[j]);
for (int i =0 ; i + SZ(y)<= SZ(x) ;i++)
{
  if (x.substr(i,SZ(y)) == y )
  {
    bool ok = 0;
    i += SZ(y);
    while (i + SZ(z) <= SZ(x))
    {
      if (x.substr(i , SZ(z)) == z)
      {
        ok = 1;
        break;
      }
      i++;
    }
    if (ok)ba = 1;
  }
}
if (fo && ba )
{
  cout << "both\n";
}else if (fo)
{
  cout <<"forward\n";
}else if (ba)
{
  cout <<"backward\n";
}else
cout <<"fantasy\n";
// TIME 
//cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
