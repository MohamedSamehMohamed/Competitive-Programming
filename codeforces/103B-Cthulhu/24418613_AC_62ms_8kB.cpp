// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int M = 100;
vector<int> adj[M];
bool seen[M];
int n, m ;
int ans ;
int find_cycle (int p , int u )
{
    seen[u] = 1;
    for (int i : adj[u])
    {
        if (i == p )continue ;
        if (seen[i] || find_cycle(u,i))return 1 ;
        seen[i]=0;
    }
    return 0 ;
}
void dfs (int u )
{
    seen[u]=1;
    for (int i : adj[u])
    {
        if (!seen[i])dfs(i);
    }
}
int main()
{
    scanf ("%d%d" , &n ,&m);
    for (int i = 0 ; i < m ;i++)
    {
        int u , v ;
        scanf ("%d%d" , &u , &v );
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i =0 ; i < n ;i++)
    {
        memset(seen,0,sizeof seen);
        int cycle_len =0 ;
        if (find_cycle(-1,i))
        {
            for (int j =0 ; j < n ;j++)
                cycle_len+=seen[j];
        }
        ans = max (ans , cycle_len);
    }
    memset(seen,0,sizeof seen);
    int cnt =0;
    for (int i =0 ; i < n ;i++)
    {
        if (!seen[i])
        {
            dfs(i);
            cnt++;
        }
    }
    if (ans > 2 && cnt==1 && n == m)
        printf("FHTAGN!\n");
    else
        printf ("NO\n");

}
