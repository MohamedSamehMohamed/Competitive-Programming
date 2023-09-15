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
int n , m ;
int a[100];
int b[100];
int main ()
{
    cin >> n >> m ;
    int c ;
    cin >> c;
    for (int i =0 ; i< c ;i++)
    {

        int t;
        cin >> t ;
        a[t]=1;
    }
    cin >> c ;
    for (int i =0 ; i < c ;i++)
    {
        int t ;
        cin >> t ;
        b[t] = 1;
    }
    for (int i =0 ; i <= 1000000 ; i++)
    {
        int l = i % n;
        int r = i % m ;
        if (a[l] || b[r])
            a[l] = b[r] = 1 ;
    }
    bool ok = 1;
    for (int i =0; i < n ;i++)ok &= a[i];
    for (int i =0 ; i < m ;i++)ok&=b[i];
    if (ok)cout <<"Yes\n";
    else
        cout <<"No\n";
    return 0;
}