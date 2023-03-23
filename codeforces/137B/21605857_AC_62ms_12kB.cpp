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
bool frq[5001];
int main()
{
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
        int u ;
        scanf ("%d" ,&u );
        frq[u]=1 ;
    }
    int ans =0 ;
    for (int i =1 ; i <= n ;i++)ans += !frq[i];
    cout << ans <<"\n";
}
