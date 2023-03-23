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
int main ()
{

    int t ;
    scanf ("%d" ,&t );
    bool fi = 0;
    while (t--)
    {
        if (fi)cout <<"\n";
        fi = 1;
        string a ;
        cin >> a ;
        int x , y ;
        x = 10 * ((int)a[0] - '0') + ((int)a[1] - '0');
        cin >> a ;
        y = 10 * ((int)a[0] - '0') + ((int)a[1] - '0');
        x--;
        y--;
        ans =0 ;
        int i =0;
        char c ;
        bool f = 1 ;
        for (int i =0 ; i< 100 ;i++)g[i] = "";
        cin.ignore();

        while (1)
        {
            scanf ("%c" , &c );
            if (c == '\n' ){
                   if (f){f = 0 ;i++;continue ; }
                    break;
            }
            f =1;
            g[i] += c;

        }
        n = i ;
        m = SZ(g[i-1]);
        memset (vis , 0 , sizeof vis );
        dfs(x,y);
        printf ("%d\n" ,ans );

    }
    return 0;
}


