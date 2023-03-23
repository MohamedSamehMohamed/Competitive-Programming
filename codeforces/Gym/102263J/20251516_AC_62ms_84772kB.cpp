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
string x ;
int n ;
ll dp[1000000][10];
ll sol (int i , int cur )
{
  if (i == -1 )return cur ;
  ll &ret = dp[i][cur];
  if (~ret) return ret ;
  int newval = (x[i] - '0') + cur ;
  cur = 0 ;
  if (newval > 9 )
  {
    newval %= 10 ;
    cur = 1;
  }
return ret = min (newval + sol (i - 1 , cur ) ,1LL * ( 10 - newval ) + sol (i - 1 , 1));
}
int main ()
{
memset (dp , -1 ,sizeof dp );
cin >> x ;
printf ("%lld\n" , sol (SZ(x)-1 , 0 ));
cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
