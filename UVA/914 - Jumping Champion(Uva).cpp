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
#include <string.h>
using namespace std ;
typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
void READ (string INPUT = "NO" , string OUTPUT = "NO" )
{
    if (INPUT != "NO")
    freopen(INPUT.c_str() , "r" , stdin );
    if (OUTPUT!="NO")
    freopen ( OUTPUT.c_str() , "w" , stdout);
}
bool siev[1000001]; 
vector <int> p;
vector <int> adj [115]; 
void solve ()
{
    int a[115]; 
    memset (a , 0 , sizeof a );
    int U , L ; 
    cin >> L >> U ; 
    for (int i =1 ; i <= 114 ;i++)
    {
      int l = 0 , r = SZ(adj[i])-1 , m , j,k;j=k=-1; 
      while (l<=r)
      {
          m = (l+r)>>1; 
          if (adj[i][m] >= L )
          {
              j = m; 
              r = m-1;
          }else 
              l = m+1; 
      }
      if (j == -1 )
      {
          continue ; 
      }
      l =0 , r = SZ(adj[i])-1; 
      while (l<=r)
      {
          m = (l+r)>>1; 
          if (adj[i][m]+i<= U)
          {
              k = m; 
              l = m+1;
          }else 
              r = m-1; 
      }
      a[i] = k-j+1; 
    }
    int mx = *max_element(a,a+115);
    int r = 0; 
    int ans ;
    for (int i =0 ; i < 115 ;i++)
        {
            if (a[i] == mx )
                ans = i; 
            r += (a[i] == mx ); 
        }
    if (r > 1 || mx == 0)
    {
        cout << "No jumping champion\n"; 
    }else 
    {
        cout <<"The jumping champion is " << ans <<"\n"; 
    }
}
int main ()
{
    for (int i = 2; i * i <= 1000001 ;i++)
    {
        if (!siev[i])
        {
            for (int j = i*2 ;j<1000001 ;j+=i)
                siev[j] =1 ; 
        }
    }
    for (int i = 2 ; i < 1000001 ;i++)
        if (!siev[i])
            p.pb(i); 
    for (int i =1 ; i < SZ(p) ;i++)
    {
     adj[abs (p[i]-p[i-1])].pb(p[i-1]); 
    }
    int T ; 
    cin >>  T ; 
    while (T--)
    {
        solve(); 
    }
    
    
    
    return 0 ; 
}  