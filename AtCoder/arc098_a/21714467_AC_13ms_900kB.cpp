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
    string s ;
    cin >> n >> s ;
    int W= 0 ;
    /// W ||  E
    int E = 0 ;
    for (int i =0 ; i < n ;i++)
    {
        if (s[i] == 'E')E++;
    }
    int ans = n+1;
    for (int i =0 ; i < n ;i++)
    {
        if (s[i] == 'E')E--;
        ans = min (ans , W + E );
        if (s[i] == 'W')W++;
    }
    printf ("%d\n" ,ans );

}
