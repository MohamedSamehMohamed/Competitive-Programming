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
const int M = 2e5 + 9 ;
int a[M];
int b[M];

int n ;
int main ()
{
    scanf ("%d" , &n);
    for (int i =0 ; i < n ;i++)scanf ("%d" , a+i);
    for (int i =0 ; i < n ;i++)
    {
        b[i] = a[i] - i-1 ;
    }
    sort(b,b+n);
    ll sum =0 ;
    for (int i =0 ; i < n ;i++)
    {
        sum += abs (a[i] - (i+1+b[n/2]));
    }
    printf ("%lld\n" ,sum );
}
