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
int t, n;
const int M = 2000 ; 
int a[M];
int LIS[M];
int LDS[M]; 
int main ()
{   
    scanf("%d" , &t ); 
    while (t--)
    {
        scanf("%d" , &n); 
        for (int i =0 ; i < n ;i++)
        {
            scanf("%d" ,a+i);
        }
        for (int i =0 ; i < n ;i++)
        {
            LIS[i] = LDS[i] = 1 ; 
        } 
        for (int i =n-2 ; i >= 0 ;i--)
        {
            for (int j = i+1 ; j < n ;j++)
            {
                if (a[j] > a[i] && LIS[j]+1 > LIS[i])
                {
                    LIS[i] = LIS[j]+1;
                }
            }   
        }
        for (int i =n-2 ; i >=0 ;i--)
        {
            for (int j = i+1 ; j < n ;j++)
            {
                if (a[j] < a[i] && LDS[j] + 1 > LDS[i])
                {
                    LDS[i] = LDS[j]+1 ; 
                }
            }
        }
        int ans =0 ;
        for (int i =0 ; i < n ;i++)
        {
            ans = max (ans , LIS[i] + LDS[i] -1 ); 
        }
        printf ("%d\n" ,ans ); 

    }
}

//10 3 13 1 4 9 8 12 6 14 5 7 2 0 11
