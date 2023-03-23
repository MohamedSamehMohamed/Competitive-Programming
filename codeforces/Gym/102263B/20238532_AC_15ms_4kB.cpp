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
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;
int main ()
{
int t ;
scanf ("%d" , &t );
while (t--)
{
  int n , k ;
  scanf ("%d%d" , &n ,&k );
  if (n == k || n-k <= 1 )
  {
    if (n % 2 )
    printf ("Kilani\n");
    else
    printf ("Ayoub\n");
    continue ;
  }
  if (n > 2 )
  printf ("Kilani\n");
  else
  printf ("Ayoub\n");
}
cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
