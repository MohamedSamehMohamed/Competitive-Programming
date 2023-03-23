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
int ss (int x )
{
    int ans =0 ;
    int k = 1;
    while (x)
    {
        if (x % 10 != 0 )
        {
            ans += (x%10)*k;
            k*=10;
        }
        x/=10;
    }
    return ans ;
}
int main()
{
    int a, b , c ;
    cin >> a >> b  ;
    c = a + b ;
    a = ss(a);
    b = ss(b);
    c = ss(c);
    if (a + b == c )
    {
        printf ("YES\n");
    }else
    printf("NO\n");
}
