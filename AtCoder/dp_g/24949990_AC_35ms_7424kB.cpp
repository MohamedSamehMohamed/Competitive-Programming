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
int n, m;
const int M = 1e5 ;
vector<int> adj[M];
int Max[M];
int dfs (int u = 0)
{
    if (Max[u] != 0 )return Max[u];
    for (int i : adj[u])
    {
        Max[u] = max (Max[u] , 1 + dfs(i));
    }
    return Max[u]; 
} 
int main ()
{
    scanf("%d%d" , &n ,&m);
    for (int i =0 ;i  < m ;i++)
    {
        int u , v;
        scanf("%d%d" , &u ,&v ); 
        u--;
        v--; 
        adj[u].pb(v); 
    }
    /*
    for each vertix find long path come to it 
    */
   int ans = 0;
   for (int i =0  ; i < n ;i++)
   ans = max (ans , dfs(i));
   printf ("%d\n" ,ans );
}
