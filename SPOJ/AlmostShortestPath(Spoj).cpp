// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <sstream>
#include <string.h>

typedef long long ll ;
#define OO 2000000000
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf ("%d" , &n ) 
#define LN(n) scanf ("%lld" , &n)
#define FOR(st,n) for (int i = st ; i < n ; i++)
using namespace std ;
int n , m ,sr,ds; 
int dist[500]; 
bool exist[500][500];
int par[500]; 
int best ; 
vector <pair<int,int>> adj[500];
void Dijkstra ()
{
    memset (dist , -1 , sizeof dist ); 
    dist[sr] = 0 ;
    priority_queue <pair<int,int>> pq ;
    pq.push({0,sr});
    par[sr] = sr; 
    while (!pq.empty())
    {
        int cur = pq.top().s ; 
        pq.pop(); 
        for (pair<int,int> v : adj[cur])
        {
            if (!exist[cur][v.f])continue ; 
            if (dist[v.f] == -1 || dist[cur] + v.s < dist[v.f])
            {
                dist[v.f] = dist[cur] + v.s ; 
                par[v.f] = cur ; 
                pq.push({-dist[v.f] , v.f }); 
            }
        }
    }
}
int dist1[500]; 
int par1[500]; 
void Dijkstra1 (int src , int destn )
{
    memset (dist1 , -1 , sizeof dist1 ); 
    dist1[src] = 0 ;
    priority_queue <pair<int,int>> pq ;
    pq.push({0,src});
    par1[src] = src; 
    while (!pq.empty())
    {
        int cur = pq.top().s ; 
        pq.pop(); 
        for (pair<int,int> v : adj[cur])
        {
            if (!exist[cur][v.f])continue ; 
            if (dist1[v.f] == -1 || dist1[cur] + v.s < dist1[v.f])
            {
                dist1[v.f] = dist1[cur] + v.s ; 
                par1[v.f] = cur ; 
                pq.push({-dist[v.f] , v.f }); 
            }
        }
    }
}
void Fast_rm (int en)
{
    if (par1[en] == en)return ;
    Fast_rm(par1[en]); 
    exist[par1[en]][en] =0; 
}
vector <int> per[500] ; 
void rm_path(int en )
{
    if (par[en] == en )return ;
    rm_path(par[en]);
    
    for (int pern : per[en]){
   
    for (pair<int,int> j : adj[pern])
    {
        if (j.f != en)continue ; 
        if (dist[pern] + j.s == dist[en] )
        {
            exist[pern][en] = 0;
        }
    }
    
    }
}
int main()
{
    while (cin >> n >> m )
    {
        
        if (n == 0 )break;
        memset (exist , 0 , sizeof exist ); 
        memset (par,0,sizeof par ); 
        for (int i =0 ; i < 500 ;i++)
            adj[i].clear(),per[i].clear();
        scanf ("%d%d" , &sr , &ds);
        
        for (int i =0 ; i < m ;i++)
        {
            int u , v, c ;
            scanf ("%d%d%d" , &u , &v ,&c ); 
            adj[u].pb({v,c});
            exist[u][v] = 1; 
            per[v].pb(u); 
        }
        Dijkstra ();
        best = dist[ds]; 
        int ans = -1 ;
        while (best != -1 )
        {
            rm_path(ds); 
            Dijkstra(); 
            ans = dist[ds];
            if (ans == -1 || ans > best )break; 
            break; 
        }
        printf ("%d\n" , ans );
        
    }
    return 0;
}
