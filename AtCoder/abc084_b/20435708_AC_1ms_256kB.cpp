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

bool kk (int j , string x )
{
  for (int i =0 ; i < SZ(x) ;i++)
  {
    if (i == j )continue ;
    if (x[i] < '0' || x[i] > '9')return false;
  }
  return true ;
}
int main ()
{
  int a , b ;
  string x ;
  cin >> a >> b >> x ;
  if (x[a] == '-' && kk (a,x))
  {
    printf ("Yes\n");
  }else
  printf ("No\n");
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
