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
int dp[2001][2001];
int n , m  , M = 1e9 + 7;
ll sol (int cur  , int len  )
{
if (len == 0 )return 1 ;
if (len < 0 || cur < 1 )return 0 ;
int &ret = dp[cur][len];
if (~ret)return ret ;
ret = 0;
for (int i = cur ; i >=  1 ; i-=cur )
{
  ret = (ret + sol (i, len + 1 ) % M ) % M ;
}
return ret ;
}
int main ()
{
string x ;
cin >> x ;
for (int i =0 ; i < SZ(x) ;i++)
{
  int ans = 1 ;
  int j = i+1 ;
  while (j < SZ(x) && x[j] == x[i])
  {
    j++;
    ans++;
  }
  i = j-1;
  cout << x[i] << ans ;
}
return 0 ;
int t ;
cin >> t ;
memset (dp , -1 ,sizeof dp );
while (t--)
{

  cin >> n >> m ;
  int ans = 0 ;
  for (int i = n; i >= 1 ;i--)
  {
    ans  = (ans + sol (i , 1) % M )%M;
  }
  cout << ans <<"\n";
}
//  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
