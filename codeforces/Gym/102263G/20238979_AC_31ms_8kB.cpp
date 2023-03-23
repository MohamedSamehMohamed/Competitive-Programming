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
int n ;
ll ans = 0 ;
scanf ("%d" , &n );
for (int i = 1 ; i < n ;i++)
{
  ans += 1LL * i * (i+1);
}
printf ("%.10lf\n" , (double)ans / n ); 
cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
