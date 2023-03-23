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
ll dp[20][(1<<20)+2];
bool vis[20][20];
int  n ;
ll sol (int id , int mask )
{
  if (id == n )return 1 ;
  ll &ret = dp[id][mask];
  if (~ret) return ret ;
  ret = 0 ;
  for (int i =0 ; i < n ;i++)
  {
    if (!vis[id][i] || (mask & (1 << i )) )continue ;
    ret += sol (id+1 , (mask | (1<<i)) );
  }
  return ret ;
}
int main ()
{
  int t ;
  scanf ("%d" , &t );
  while (t--)
  {
    scanf ("%d" ,&n );
    for (int i =0 , tm ; i < n ;i++)for (int j =0 ; j < n ;j++)scanf ("%d" , &tm)  , vis[i][j] = tm ;
    memset (dp , -1 , sizeof dp );
    printf ("%lld\n" , sol (0,0));
  }
  return 0;
}
