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
const int M = 2009 ;
const int Lg = 15  ; 
int a[M][M];
int dist[M][M];
int arr[M][M]; 
vector<pair<int,int>> adj[M]; 
int n;
bool seen[M];
int in[M],en[M];
int Par[M][Lg];
ll dp[M][Lg];
int root ;
int idx ;
bool buildTree ()
{
    priority_queue<pair<ll,pair<int,int>>> pq ;
    for (int i =1 ; i < n ;i++)
    {
        pq.push( { -a[0][i] , {0 , i} } );
    }
    seen[0] = 1 ;
    int rm=n-1 ;
    while (rm != 0 && !pq.empty())
    {
        auto curq = pq.top();
        pq.pop();
        int node = curq.s.s ;
        int p = curq.s.f ;
        int cst = -curq.f;
        if (seen[node])continue ; 
        seen[node] = seen[p] = 1 ;
        arr[node][p] = arr[p][node] = cst ;
        rm--;
        for (int i =0 ;i < n ; i++)
        {
            if (seen[i] || i == p || i == node )continue ; 
            pq.push({ -a[node][i], {node,i} });
        }
        
    }
    return rm == 0 ; 
}
void dfs (int u = root , int par = root , int cost = 0)
{
    
    in[u] = idx ;
    idx++; 
    Par[u][0] = par ;
    dp[u][0]  = cost ;  
    for (int i=1 ,curp;  i < Lg ;i++)
    {
        curp = Par[u][i-1];
        Par[u][i] = Par[ curp ][i-1];
        dp[u][i]  = dp[u][i-1] + dp[curp][i-1];
    }
    for (auto v : adj[u])
    {
        if (v.f == par)continue ;
        dfs (v.f , u , v.s); 
    }
    en[u] = idx;
    idx++; 
}
bool isLCA(int u, int v)
{
    return in[u] <= in[v] && en[u] >= en[v]; 
}
int LCA (int u, int v)
{
    if (isLCA(u,v))return u ; 
    if (isLCA(v,u))return v ;
    for (int i = Lg -1 ; i >= 0 ;i--)
    {
        u = isLCA(Par[u][i] , v ) ? u : Par[u][i]; 
    }
    return Par[u][0];
}
ll distance (int u, int v, int lca )
{
    // O(1) time 
    return dp[u][Lg-1] + dp[v][Lg-1] - 2LL*dp[lca][Lg-1];  
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < n ;j++)
        {
            cin >> a[i][j];
        }
    }
    
    bool valid = 1 ; 
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < n ;j++)
        {
            dist[i][j] = 2e9 ; 
            if (i == j )
            valid &= (a[i][j] == 0); 
            else 
            valid &= (a[i][j] == a[j][i] && a[i][j]); 
        }
    }
    if (!valid || !buildTree())
    {
        cout <<"NO\n";
        return 0;
    }
    
    for (int i =0 ; i < n ;i++)
    {
        for (int j=i+1 ; j < n ;j++)
        {
            if (arr[i][j] == 0)continue ;
            adj[i].pb({j,arr[i][j]}); 
            adj[j].pb({i,arr[i][j]}); 
        }
    }
    for (int i =0 ; i < n ;i++)
    {
        if (SZ(adj[i]) == 1 )
        {
            root = i ; 
        }
    }
    dfs();
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < n ;j++)
        {
            if (i == j)continue ;
            if (distance(i , j , LCA(i,j)) != a[i][j])
            {
                cout <<"NO\n";
                return 0;
            }
        }
    }
    cout <<"YES\n";


    

}