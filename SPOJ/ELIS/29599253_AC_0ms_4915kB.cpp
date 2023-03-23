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
int n  ;
int dp[10][11];
int a[10];
int sol (int id ,int cur )
{
  if (id == n )return 0 ;
  if (dp[id][cur] != -1 )return dp[id][cur];
  int &ret = dp[id][cur];
  ret = sol (id+1 , cur );
  if (a[id] > a[cur])
  ret = max (ret , 1 + sol (id+1 , id));
  return ret ;
}
int main ()
{
  memset (dp , -1 ,sizeof dp ); 
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++)
  {
    scanf ("%d" , a+i );
  }
  printf ("%d\n" , sol (0 , 10 ));
  return 0;
}
