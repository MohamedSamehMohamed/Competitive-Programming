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
const int M = 200 ;
int n , m ;
vector<int> adj[M];
int col[M];
bool Bi ()
{
    queue<int> q;
    q.push(0);
    col[0] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int node : adj[cur])
        {

            if (col[node] == -1 )
            {
                col[node] = 1 - col[cur];
                q.push(node);
            }else if ( col[node] == col[cur] )
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    while (scanf ("%d", &n) == 1 && n)
    {
        scanf ("%d" , &m );
        for (int i =0 ; i < M ;i++){
                adj[i].clear();
                col[i] = -1 ;
        }
        for (int i =0 ; i < m ;i++)
        {
            int u , v;
            scanf ("%d%d" , &u , &v );
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if ( Bi() )
            printf ("BICOLORABLE.\n");
        else
            printf ("NOT BICOLORABLE.\n");

    }
}
