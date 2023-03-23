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
int n ;
int a[100000];
int main()
{

    scanf ("%d" ,&n );
    for (int i =0 ; i < n ;i++)scanf ("%d" ,a+i );
    ll ans = n ;
    for (int i = 0 ; i < n ;i++)
    {
        int j = i+1 ;
        while (j < n && a[j] == a[j-1])j++;
        int len = j-i;
        i = j-1;
        ans += (1LL*len * (len-1) )/ 2;
    }
    printf("%lld\n" ,ans );
}
