// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
string s ;
ll dp[61][61];
ll solve (int l =0 , int r = SZ(s)-1)
{

   // aa -> a , a , aa 
   if (l + 1 == r)
   return (s[l] == s[r]) + 2;  
   
   if (l == r )return 1 ; 
   
   ll &ret = dp[l][r];
   if (~ret)return ret ; 
   ret =0 ;
   if (s[l] == s[r])
   ret += 1 + solve(l+1 , r-1); 
   ret += solve(l+1,r); 
   ret += solve(l,r-1); 
   /// exclude  
   ret -= solve(l+1,r-1);
   return ret ; 
}
int main ()
{   
    int t;
    cin >> t ;
    while (t--)
    {
        cin >> s ;
        memset(dp , -1 , sizeof dp);
        cout << solve() <<"\n";
    }
}

