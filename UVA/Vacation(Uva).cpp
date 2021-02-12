// Author : Mohamed Sameh
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

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf ("%d" , &n ) 
#define LN(n) scanf ("%lld" , &n)
#define FOR(st,n) for (int i = st ; i < n ; i++)
using namespace std ;
int T ; 
string x , y ;
int dp[100][100]; 
int sol (int i , int j )
{
    if (i == SZ(x) || j == SZ(y))return 0; 
    int &ret = dp[i][j]; 
    if (ret != -1 )return ret ; 
    if (x[i] == y[j])
        ret = 1 + sol (i+1 , j+1 ); 
    else 
        ret = max (sol(i+1,j) , sol(i,j+1)); 
    return ret ; 
}
int main ()
{
    for (int i = 1 ;  ; i++)
    {
        memset (dp , -1 ,sizeof dp );
        getline (cin , x);
        if (x[0] == '#')break;
        getline (cin , y );
        printf ("Case #%i: you can visit at most %d cities.\n" , i , sol(0,0));
    }
      return 0;
}