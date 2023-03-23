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
int main()
{
    int n ;
    scanf ("%d" , &n );
    n*=n;
    for (int i =1 ; i <= n - i +1 ;i++)
    {
        printf ("%d %d\n" , i , n-i+1 );
    }
}
