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
vector <int> adj[100000];
int ans , n , m ;
bool col[100000];
int main()
{
    scanf ("%d%d" , &n , &m );
    for (int i =0 , j ; i < n ;i++)scanf ("%d" ,&j ),col[i] = j ;
    for (int i = 1; i < n ;i++)
    {
        int u , v ;
        scanf ("%d%d" , &u , &v );
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue <pair<pair<int,int>,int>> q ;
    q.push({{0,-1},col[0]});
    while (!q.empty())
    {
        pair<int,int> cur = q.front().f ;
        int lim = q.front().s ;
        q.pop();
        if (lim > m)continue ;
        if (SZ(adj[cur.f]) == 1 && cur.s != -1 ){ans++;continue;}
        for (int i : adj[cur.f])
        {
            if (i == cur.s )continue ;
            q.push({{i , cur.f} , lim*col[i] + col[i] });
        }
    }
    printf ("%d\n" ,ans );

}