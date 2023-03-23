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
const int M = 200 ;
int n , m ;
vector <pair<int,int>> adj[M] , mst[M];
bool vis[M];
int from , to ;
int BFS ()
{
    memset(vis,0,sizeof vis );
    queue <pair<int,int>> q ;
    q.push({from , 2e9 });
    vis[from] = 1 ;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.f == to )return cur.s ;
        for (auto i : mst[cur.f])
        {
            if (vis[i.f])continue ;
            vis[i.f]=  1;
            q.push({i.f , min (cur.s ,i.s) });
        }
    }
}
void solve (int T )
{

    for (int i =0 ; i < n ; i++)vis[i] = 0 , adj[i].clear() , mst[i].clear();
    map <string , int > mp ;
    int id =0 ;
    for (int i =0 ; i < m ;i++)
    {
        string x , y ;
        int u , v , c ;
        cin >> x >> y >> c ;
        if (mp.find(x) == mp.end())
        {
            mp[x] = id++;
        }
        if (mp.find(y) == mp.end())
        {
            mp[y] = id++;
        }
        u = mp[x];
        v = mp[y];
        adj[u].pb({v , c });
        adj[v].pb({u , c });
        if (i + 1 == m )
        {
            cin >> x >> y ;
            from  = mp[x] ;
            to = mp[y];
        }
    }
    priority_queue <pair<pair<int,int>,int>> pq ;
    for (auto i : adj[0])
    {
        pq.push({{i.s,i.f},0});
    }
    vis[0] =1 ;
    while (!pq.empty())
    {
        auto cur = pq.top().f;
        int par = pq.top().s ;
        pq.pop();
        if (vis[cur.s])continue ;
        vis[cur.s] = 1;
        mst[cur.s].pb({par,cur.f});
        mst[par].pb({cur.s , cur.f });
        for (auto i : adj[cur.s])
        {
            pq.push({{i.s, i.f },cur.s});
        }
    }
    printf ("Scenario #%d\n%d tons\n\n" , T , BFS());
}
int main()
{

    for (int i = 1;  ;i++)
    {
        scanf ("%d%d" , &n ,&m );
        if (!(n||m))break;
        solve (i);
    }
}
