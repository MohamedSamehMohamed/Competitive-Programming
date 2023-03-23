// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}
using namespace std ;
/*
int ans ;
bool vis[1000][1000];
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};
int n , m ;
string g[1000];
void dfs (int x , int y )
{
    //cout << x + 1  <<" " << y + 1  <<"\n";
    if (vis[x][y])return ;
    vis[x][y] =1 ;
    ans++;
    for (int i =0 ; i < 4 ;i++)
    {
        int nx = X[i] + x;
        int ny = Y[i] + y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || g[nx][ny] == '1')continue ;
        dfs(nx,ny);
    }
}

bool dec (int x )
{
    while (x)
    {
        if (x%10 == 4 )return true ;
        //if (x%100 == 13)return true ;
        x/=10;
    }
    return false ;
}
*/
int n , k ;
double dp[300][300][300];
bool vis[300][300][300];
int x[300] , y[300];
double dist (int i , int j)
{
    return sqrt (pow(x[i] - x[j] , 2 ) + pow (y[i] - y[j] , 2));
}
double sol (int last ,int cur , int rm )
{
    if (cur == n )
    {
        if (rm == 0 )return 0;
        return 1e12 ;
    }
    double &ret = dp[last][cur][rm];
    if (vis[last][cur][rm])return ret ;
    vis[last][cur][rm] = 1;
    ret = dist(last , cur ) + sol (cur , cur + 1, rm );
    if (cur !=0 && cur != n-1 )
    {
        ret = min (ret , sol (last , cur + 1 ,rm - 1));
    }
    return ret ;
}
int main ()
{
    while (scanf ("%d%d" , &n ,&k) == 2 )
    {
        for (int i =0 ; i < n ;i++)
        {
            cin >> x[i] >> y[i] ;
        }
        memset (vis , 0 ,sizeof vis );
        double ans = sol (0 , 1 , k ) ;

        printf ("%.3f\n" , ans );
    }

    return 0;
}


