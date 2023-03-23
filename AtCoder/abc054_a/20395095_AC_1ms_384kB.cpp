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
  int a , b ;
  cin >> a >> b ;
  if (a == b )
  {
    cout <<"Draw\n";
  }else
  {
    if (a == 1 || ( b != 1 && a > b ))
    cout << "Alice\n";
    else
    cout << "Bob\n";
  }
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
