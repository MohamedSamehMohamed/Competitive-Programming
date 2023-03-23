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
    int x , y , x1 , y1 ;
    cin >> x >> y >> x1 >> y1 ;
    int ans = abs (x - x1 ) + abs (y - y1  );
    printf ("%d\n" ,ans );
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
