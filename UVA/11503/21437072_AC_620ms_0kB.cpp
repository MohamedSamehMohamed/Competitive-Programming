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
const int M = 1e5 + 9 ;
int par[M];
int Rank[M];
void rec ()
{
    for (int i =0 ; i < M ;i++)par[i] = i ,Rank[i] = 1;
}
int findpar (int u )
{
    if (par[u] == u )return u ;
    return par[u] = findpar(par[u]);
}
void join (int u , int v )
{
    u = findpar(u);
    v = findpar(v);
    if (u != v )
    {
        if (Rank[u] > Rank[v])swap(u,v);
        par[v] = u ;
        Rank[u] += Rank[v];
    }
}
int main()
{


    int t ;
    scanf ("%d" , &t );
    while (t--)
    {
        int n ;
        scanf ("%d" , &n );
        rec();
        int id =0 ;
        map <string , int > mp ;
        for (int i =0 ; i < n ;i++)
        {
            string x , y ;
            cin >> x >> y ;
            if (mp.find(x) == mp.end())
            {
                mp[x] = id++;
            }
            if (mp.find(y) == mp.end())
            {
                mp[y] = id++;
            }
            int u = mp[x];
            int v = mp[y];
            join(u,v);
            u = findpar(u);
            v = findpar(v);
            cout << max (Rank[u] , Rank[v]) <<"\n";
        }
    }

}
