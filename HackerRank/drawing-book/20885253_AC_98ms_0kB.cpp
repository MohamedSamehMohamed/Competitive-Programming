// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;

int main ()
{
    int n , p ;
    cin >> n >> p;
    if (p == 1 || p >= n - n%2 ){
        cout << 0 <<"\n";
        return 0;
    }
    int ans = p / 2 ;
    int cur = (n % 2 == 0)  ;
    if (n % 2 == 0 )n--;
    while (n > p )
    {
        if (p == n || p == n-1 )break;
        n-=2 ;
        cur++;
    }
    cout <<  min (cur , ans ) <<"\n";
    return 0;
}
