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
int par[21];
int cost[21][21];
bool vis[21];
vector<int> Path[21];
vector<pair<int,int>> adj[21] , mst[21];
int n , m,dst,k,ans;
void dfs (int u , int v , int p )
{
    if (u == v )return ;
    for (auto i : mst[u])
    {
        if (i.f == p)continue ;
        par[i.f] = u ;
        dfs(i.f , v , u );
    }
}
stack <int> stk;
void printpath(int u )
{
    if (par[u] != -1 )printpath(par[u]);
    if (par[u] != -1 )
    {
        ans += cost[u][ par[u] ];
        cost[u][ par[u] ] = cost[ par[u] ][u] = 0;
    }
    stk.push(u);
}
void Cal (int u , int v , int id )
{
    memset(par,0,sizeof par );
    par[u] = -1 ;
    dfs (u , v , -1 );
    printpath(v);
    while (!stk.empty())
    {
        Path[id].pb(stk.top());
        stk.pop();
    }
}
void solve (int T)
{
    memset(cost , 0 , sizeof cost );
    for (int i =0 ; i <= n;i++)adj[i].clear(),vis[i]=0,mst[i].clear(),Path[i].clear();
    scanf ("%d" , &dst );
    scanf ("%d" , &m );
    for (int i =0 ; i < m ;i++)
    {
        int u , v , c ;
        scanf ("%d%d%d" , &u , &v , &c );
        adj[u].pb({v,c});
        adj[v].pb({u,c});
        cost[u][v] = cost[v][u] = c ;
    }
    scanf ("%d" , &k);
    priority_queue<pair<pair<int,int>,int>> pq ;
    for (auto i : adj[1])pq.push({{-i.s , i.f },1});
    vis[1] = 1;
    while (!pq.empty())
    {
        pair<int,int> cur = pq.top().f;
        int last = pq.top().s ;
        pq.pop();
        cur.f*=-1;
        if (vis[cur.s])continue ;
        vis[cur.s] = 1 ;
        mst[last].pb({cur.s , cur.f });
        mst[cur.s].pb({last , cur.f });
        for (auto i : adj[cur.s])
        {
            pq.push({{-i.s,i.f},cur.s});
        }
    }
    // Not All The Cost Of MST
    ans =0 ;
    for (int i =0 ; i < k ;i++)
    {
        int u ;scanf ("%d" , &u);
        Cal(dst , u , i);
    }
    printf ("Case %d: distance = %d\n" , T , ans );
    for (int i =0 ; i < k ;i++)
    {
        printf ("   ");
        for (int j =0 ; j < SZ(Path[i]) ; j++)
        {
            printf ("%d" , Path[i][j]);
            if (j + 1 < SZ(Path[i]))printf ("-");
            else
                printf("\n");
        }
    }
    printf ("\n");
}
int main()
{

    for (int i = 1;   ;i++)
    {
        scanf ("%d" , &n );
        if (n == -1 )break ;
        solve(i);
    }

}
