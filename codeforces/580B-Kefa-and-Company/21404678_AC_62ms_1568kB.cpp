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
int n , m ;
ll pre[100001];
int main()
{
    scanf ("%d%d" , &n ,&m);
    vector <pair<int,int>> v (n);
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d%d" ,&v[i].f ,&v[i].s);
    }
    sort(all(v));
    ll ans =0 ;
    for (int i = 1; i <= n ; i++)
        pre[i] = pre[i-1] + v[i-1].s ;
    for (int i =0 , j =0 ; j < n ;i++)
    {
        if (j < i ) j = i;
        while (j + 1 < n && v[j+1].f - v[i].f < m )
        {
            j++;
        }
        if (v[j].f - v[i].f < m )
        ans = max (pre[j+1] - pre[i] , ans );
        if (j < i + 1 ) j = i+1 ;
    }
    cout << ans <<"\n";

}
