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
const int M =2000;
vector<pair<int,int>> adj[M];
bool vis[M];
int n , m ;
int main()
{
    int t ; scanf ("%d" , &t );
    while (t--)
    {
        scanf ("%d%d" , &n ,&m);
        for (int i =0 ; i < n ;i++)adj[i].clear(),vis[i]=0;
        map <string , int > mp ;
        int id =0 ;
        for (int i =0 ; i < m ;i++)
        {
            int u , v , c ;
            string x ;
            cin >> x ;
            if (mp.find(x) == mp.end())
            {
                mp[x] = id++;
            }
            u = mp[x];
            cin >> x ;
            if (mp.find(x) == mp.end())
            {
                mp[x] = id++;
            }
            v = mp[x];
            cin >> c ;
            adj[u].pb({v ,c });
            adj[v].pb({u , c });
        }
        int ans =0 ;
        vis[0] = 1;
        priority_queue <pair<int,int>> pq ;
        for (auto i : adj[0])
        {
            pq.push({-i.s,i.f});
        }
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (vis[cur.s])continue ;
            vis[cur.s] = 1;
            ans += -cur.f ;
            for (auto i : adj[cur.s])pq.push({-i.s,i.f});
        }
        printf ("%d\n" ,ans );
        if (t)printf ("\n");
    }


}
