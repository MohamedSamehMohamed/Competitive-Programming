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
int val[500];
vector <int> adj[500];
int cost[500][500];
int main ()
{
    int n , m ;
    cin >> n >> m ;
    for (int i =0 ; i < n ;i++)
    {
        cin >> val[i];
    }
    for (int i =0 ; i < m ;i++)
    {
        int a, b, c ;
        cin >> a >> b >> c ;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        cost[a][b] = cost[b][a] = c ;
    }
    double ans = 0 ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j = i+1 ; j < n ;j++)
        {
            int v = val[i] + val[j];
            int e = cost[i][j];
            if (e == 0 )continue ;
            ans = max (ans , 1.0*v / e );
        }
    }
    printf ("%.10f\n" , ans );
    return 0;
}
