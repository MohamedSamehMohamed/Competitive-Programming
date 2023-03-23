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
  string x , y ;
  cin >> x >> y;
  x += y ;
  int a = 0 ;
  for (int i = SZ(x)-1 , k = 1;i >=0 ; i-- , k*=10)
  a += ((int)x[i] - '0') * k ;
  int b = sqrt (a);
  if (a == b * b )
  printf ("Yes\n");
  else
  printf ("No\n"); 
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
