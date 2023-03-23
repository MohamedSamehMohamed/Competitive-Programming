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
const int M  = 1e5 ;
const int Lg = 20  ;
int spt[M][Lg];    
int n;
int a[M];
int LOG[M+1];
map<int,ll> ans ;    
void ConstructForGCD()
{
    // if overlap doesn't affect the answer we can get the answer in O (1) time. 
    LOG[1] = 0;
    for (int i = 2; i < M+1 ;i++)
    {
        LOG[i] = LOG[i/2] + 1 ; 
    }
    for (int i =0 ; i < n ;i++)
    spt[i][0] = a[i];
    for (int p = 1; p < Lg ;p++)
    {
        for (int i =0 ; i + (1<<p) <= n;i++)
        {
            spt[i][p] = __gcd(spt[i][p-1] , spt[i+(1<<(p-1))][p-1]); 
        }
    }
}
int queryGCD (int l, int r)
{
    int p = LOG[r - l + 1 ];
    return __gcd(  spt[l][p] , spt[r - (1<<p) + 1 ][p] );
}
void getR(int left ,int l, int r , int tar, int &R)
{
    // non increase < < < < 9 8 8 5 5 4 4 
    while (l <= r )
    {
        int m = (l+r)>>1 ;
        int curg = queryGCD(left , m );
        if (curg >= tar )
        {
            if (curg == tar)R = m ; 
            l = m+1 ;
        }else 
        {
            r = m-1 ; 
        }
    }
}
void calallGCD()
{
    for (int i =0 ; i < n ;i++)
    {
        int j =i;
        int tar ;
        while ( j < n )
        {
            tar = queryGCD(i,j);
            int R = j;
            getR(i,j,n-1,tar,R);
            ans[tar]+=(R - j + 1 ); 
            j = R + 1 ;
        }
    }
}
int main()
{
    /*
        -the idea is that the number of distinct gcd is small. 
        - gcd (i , j ) >= gcd (i , j + x) >= gcd (i , j + y ) , x <= y 
    */
    scanf("%d" , &n );
    for (int i =0 ; i < n ;i++)
    {
        scanf("%d" , a+i);
    }
    ConstructForGCD();
    calallGCD();
    int q ;
    scanf("%d" , &q ); 
    while (q--)
    {
        int x; 
        scanf("%d" , &x );
        printf("%lld\n" , ans[x]);
    }
    
}