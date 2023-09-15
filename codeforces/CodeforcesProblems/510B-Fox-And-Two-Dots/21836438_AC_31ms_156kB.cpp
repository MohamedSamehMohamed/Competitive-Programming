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
string g[50];
int X[] = {1 , -1 , 0 , 0 };
int Y[] = {0 , 0 , 1 , -1 };
bool vis[50][50];
bool dfs (  pair<int,int> u , pair<int,int> par  )
{
    vis[u.f][u.s] = 1;
    for (int i =0 ; i < 4 ; i++)
    {
        int nx = X[i] + u.f ;
        int ny = Y[i] + u.s ;
        if (nx == par.f && ny == par.s )continue ;
        if (min(nx , ny) < 0 || nx >= n || ny >= m || g[nx][ny] != g[u.f][u.s])continue ;
        if (vis[nx][ny] || dfs ({nx , ny} , u ))return true ;
    }
    return false ;
}
int main()
{
    cin >> n >> m ;
    for (int i =0 ; i < n ;i++)cin >> g[i];
    for (int i =0 ; i < n ;i++)
        for (int j =0 ; j < m ;j++)
    {
        if (!vis[i][j] && dfs({i,j} , {-1 , -1 }))
            {
                printf ("Yes\n");
                return 0;
            }
    }
    printf("No\n");
}
