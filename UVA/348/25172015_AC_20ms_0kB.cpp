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
int n;
int a[10][2]; 
int dp[10][10];
int bestsplit[10][10]; 
int ans[10][2]; 
void solve (int l, int r )
{
    if (bestsplit[l][r] == -1  )
    {
        if (l != r )
        {
            ans[l][0]++; 
            ans[r][1]++; 
        }
        return ; 
    }
    if (l != r )
    {
        ans[l][0]++; 
        ans[r][1]++; 
    }
    solve(l , bestsplit[l][r]); 
    solve(bestsplit[l][r]+1 , r ); 
}
void test ()
{ 
   for (int i =0 ;i < n;i++)
   for (int j =0 ;j < n;j++)
   dp[i][j] = 1e9;
   memset(bestsplit,-1,sizeof bestsplit);
   for (int i=0; i< n ;i++)dp[i][i] =0; 
   for (int i =0; i + 1 < n ;i++)
   dp[i][i+1] = a[i][0] * a[i][1] * a[i+1][1]; 
   
   for (int k=2 ; k < n ;k++){
    for (int i=0 ;i+k < n ;i++)
    {
        int mj = -1;
        for (int j = i ; j < i+ k;j++)
        {
        /*
        cost of multiply matrices from i : j     = dp[i][j]
        cost of multiply matrices from j+1 : i+k = dp[j+1][i+k]
        cost of multiply result matrix from (i:j) and (j+1:i+k) = a[i][0] * a[j][1] *a[i+k][1]
        */
        int cur = dp[i][j] + dp[j+1][i+k] + a[i][0]*a[j][1]*a[i+k][1] ;
        dp[i][i+k] = min (dp[i][i+k] , dp[i][j] + dp[j+1][i+k] + a[i][0]*a[j][1]*a[i+k][1]);
        if (cur == dp[i][i+k])
        {
            mj = j ;
        }
        }
        if (mj != -1 )
        {
            bestsplit[i][i+k] = mj ; 
        }
         
    }
    }
    solve(0 , n-1);
    for (int i =0 ; i < n ;i++)
    {
        while (ans[i][0] > 0 )
        {
            cout <<"("; 
            ans[i][0]--; 
        }
        cout << "A" << i+1 ; 
        while (ans[i][1] > 0)
        {
            cout << ")"; 
            ans[i][1]--;
        }
        if (i+1 < n )
        {
            cout <<" x ";
        }else 
        cout <<"\n"; 
    }
    
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i =1 ;cin >> n && n ;i++)
    {
        
        for (int j =0 ; j < n ;j++)
        cin >> a[j][0] >> a[j][1]; 
        cout << "Case " << i  <<": ";
        test(); 
    }
}
