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
set<int> adj[101];
int main()
{
scanf ("%d%d" ,&n ,&m);
for (int i =0 ; i < m ;i++)
{
    int u , v ;
    scanf ("%d%d" , &u ,&v );
    adj[u].insert(v);
    adj[v].insert(u);
}
int ans =0 ;
while (1)
{
    vector <int> rm ;
    for (int i =1 ; i <= n ;i++)
    {
        if (SZ(adj[i]) == 1 )
        {
            rm.pb(i);
        }
    }

    if (SZ(rm) == 0 )break ;
    for (int i =0; i < SZ(rm) ;i++)
    {
        int u = *adj[rm[i]].begin();
        int v = rm[i];
        adj[u].erase(v);
        adj[v].erase(u);
    }
    ans++;
}
printf ("%d\n" ,ans );

}
