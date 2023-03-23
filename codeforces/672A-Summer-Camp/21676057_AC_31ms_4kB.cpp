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
string ans ;
int n ;
void ins (int x )
{
    string tm = "";
    while (x)
    {
        tm += char (  (x%10) + '0' );
        x/=10;
    }
    reverse(tm.begin() , tm.end());
    ans += tm ;
}
int main()
{
    scanf ("%d" , &n );
    int i = 1;
    while (SZ(ans) < n )
    {
        ins(i);
        i++;
    }
    cout << ans[n-1] <<"\n";
}
