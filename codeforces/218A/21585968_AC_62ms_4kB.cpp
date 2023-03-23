// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int a[201];
int main()
{

    int n , k ;
    scanf ("%d%d" , &n ,&k);
    for (int i =0 ; i < 2*n+1 ;i++)
    {
        scanf ("%d" ,a+i);
    }
    for (int i = 1 ; k && i < 2*n+1 ; i+=2 )
    {
        if (a[i]-1 > a[i-1] && a[i]-1 > a[i+1]){
        a[i]--;
        k--;
        }
    }
    for (int i =0 ; i < 2*n+1 ;i++)
    {
        printf ("%d " , a[i]);
    }
    printf ("\n");
}
