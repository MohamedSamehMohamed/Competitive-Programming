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
const int M = 1e2 + 1; 
int a[M] , b[M], n, k; 
map< pair<int,int> ,int> dp ; 
/*
    sum (a) / k = sum(b)
    sum(a) = sum(b) * k 
    (2 + 2 ) * 3 
    4 * 3 = 6 +  6 
    sum(a) - sum(b) * k == 0 
*/
int solve (int i =0 , int sum =0 )
{
    if (i == n )
    {
        if (sum != 0 )return -1e9 ;
        return 0; 
        
    }
    if (dp.find({i , sum}) != dp.end())return dp[{i,sum}]; 
    int cur = solve(i+1 , sum ); 
    cur = max (cur , a[i] + solve(i+1 , sum + (a[i] - b[i]))); 
    return dp[{i,sum}] = cur ;
}
int main ()
{   
    scanf ("%d%d" , &n ,&k);
    for (int i =0 ; i < n ;i++)
        scanf ("%d" ,a+i);
    for (int i =0 ; i < n ;i++)
        scanf ("%d" ,b+i) , b[i] *= k; 
    printf ("%d\n" , solve() <= 0 ? -1 : solve());  
    
}

