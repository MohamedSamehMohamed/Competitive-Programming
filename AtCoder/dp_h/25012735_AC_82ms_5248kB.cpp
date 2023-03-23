// Author : MohamedSameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <sstream>
#include <string.h>

typedef long long ll ;
// random in each run --> srand(time(NULL));

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
int n , m , M = 1e9+7;
string x[1000];
int dp[1000][1000];
ll sol (int i , int j )
{
  if (i >= n || j >= m || i < 0 || j < 0 || x[i][j] == '#')return 0 ;
  if (i == n-1 && j == m-1)return 1 ;
  int &ret = dp[i][j];
  if (~ret)return ret ;
  ret = 0 ;
  return ret = (ret + sol(i+1 , j)%M + sol (i , j+1 )%M)%M ;
}
int main ()
{
memset (dp , -1 ,sizeof dp );
scanf ("%d%d" , &n ,&m );
for (int i =0 ; i < n ;i++)cin >> x[i];
printf ("%lld\n" ,sol (0,0)%M );
  return 0;
}
