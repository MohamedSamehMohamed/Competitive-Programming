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
vector <pair<int,int>> adj[1000000];
bool vis[1000000];
int main()
{
    while (scanf ("%d%d" , &n , &m))
    {
        if (!n && !m )break;
        for (int i =0 ; i < n ;i++)adj[i].clear(),vis[i]=0;
        for (int i =0 ; i < m ;i++)
        {
            int u ,v , c ;
            scanf ("%d%d%d" , &u , &v , &c );
            adj[u].pb({v,c});
            adj[v].pb({u,c});
        }
        int ans = -1 ;
        int node = 0 ;
        priority_queue<pair<int,int>> q ;
        for (auto i : adj[0])
        {
            q.push({-i.s , i.f });
        }
        while (!q.empty())
        {
            pair<int,int> cur = q.top();
            q.pop();
            cur.f *=-1 ;
            if (vis[cur.s])continue ;
            vis[cur.s] = 1 ;
            node++;
            ans = max (ans ,cur.f );
            for (auto i : adj[cur.s])
            {
                if (vis[i.f])continue ;
                q.push({-i.s , i.f });
            }
        }
        if (node == n )
            printf ("%d\n" , ans );
        else
            printf ("IMPOSSIBLE\n");

    }
}
