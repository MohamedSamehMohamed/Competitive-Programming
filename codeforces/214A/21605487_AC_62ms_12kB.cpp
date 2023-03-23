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
    int n , m ;
    scanf ("%d%d" , &n ,&m);
    int ans =0 ;
    for (int i =0 ; i <= 1000 ;i++)for (int j =0 ; j <= 1000 ; j++) ans += (i*i+j==n && i + j*j == m );
    cout << ans <<"\n";
}
