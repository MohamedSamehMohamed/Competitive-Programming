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
int n,q ;
const int M = 2e5;
vector<int> adj[M];
int sublen[M];
int Indx[M];
vector<int> ans;
void dfs (int u =0 , int par = -1 )
{
    ans.pb(u);
    sublen[u]++;
    for (int i : adj[u])
    {
        if (i != par )
        {
            dfs (i,u);
            sublen[u] += sublen[i];
        }
    }
}
int main()
{
    cin >> n >> q ;
    for (int i=1 ; i <n ;i++)
    {
        int x ;
        cin >> x ;
        x--;
        adj[x].pb(i);
        adj[i].pb(x);
    }

    dfs ();
    for (int i =0 ;i < SZ(ans) ;i++)
    {
        Indx[ ans[i] ] = i ;
    }

    while (q--)
    {
        int u , k;
        cin >> u >> k ;
        u--;
        if (sublen[u] >= k )
        {
            cout << ans[ Indx[u] + k - 1 ] + 1  <<"\n";
        }else
        cout <<"-1\n";
    }

}