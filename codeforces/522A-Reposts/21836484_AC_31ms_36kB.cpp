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
int n ;
vector<int> adj[400];
map <string , int > mp ;
int ans ;
int dfs (int u , int par , int dp )
{
    ans = max (ans , dp );
    for (int i : adj[u])
    {
        if (i != par )
        {
            dfs (i , u , dp + 1 );
        }
    }
}
int main()
{
    cin >> n ;
    int id =0 ;
    while (n--)
    {
        string x , y , z ;
        cin >> x >> y >> z ;
        for (int i =0 ; i < x.size() ;i++)
        {
            if (x[i] < 'a')x[i] += 32;
        }
        for (int i =0 ; i < z.size() ;i++)
            if (z[i] < 'a')z[i] += 32 ;
        int u , v ;
        if (mp.count(x) == 0 )mp[x] = id++;
        if (mp.count(z) == 0 )mp[z] = id++;
        u = mp[x];
        v = mp[z];
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs (mp["polycarp"] , -1 , 1);
    cout << ans <<"\n";
}
