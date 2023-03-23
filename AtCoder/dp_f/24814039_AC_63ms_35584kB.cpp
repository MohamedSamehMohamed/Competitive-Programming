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
string s,t ;
int n,m; 
const int M = 3000;
int dp[M][M]; 
void PrintAnswer(int i = n-1 , int j = m-1)
{
    if (i < 0 || j < 0 )return ; 
    if (i == j && i == 0 )
    {
        if (s[0] == t[0])
        cout << s[0]; 
        return ; 
    }
    if (i-1 >= 0 && dp[i][j] == dp[i-1][j])
    {
        PrintAnswer(i-1,j); 
    }else if (j-1 >=0  && dp[i][j] == dp[i][j-1])
    {
        PrintAnswer(i,j-1); 
    }else 
    {
        PrintAnswer(i-1,j-1); 
        cout << s[i]; 
    }
}
int main ()
{   
    cin >> s >> t ;
    n = SZ(s);
    m = SZ(t);
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            if (s[i] == t[j])
            {
                if (i-1 >= 0 && j-1 >= 0)
                dp[i][j] = dp[i-1][j-1] + 1 ; 
                else 
                dp[i][j] = 1;   
            }else 
            {
                if (i - 1 >= 0 )dp[i][j] = max (dp[i][j] , dp[i-1][j]); 
                if (j - 1 >= 0 )dp[i][j] = max (dp[i][j] , dp[i][j-1]); 
            }
        }
    }
    PrintAnswer(); 

}