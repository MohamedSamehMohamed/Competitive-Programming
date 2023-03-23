// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <cstring>
#include <iomanip>    
using namespace std ;
typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
void READ (string INPUT = "NO" , string OUTPUT = "NO" )
{
    if (INPUT != "NO")
    freopen(INPUT.c_str() , "r" , stdin );
    if (OUTPUT!="NO")
    freopen ( OUTPUT.c_str() , "w" , stdout);
}
map <int , vector <pair<int,int>>>ROW ; 
struct node 
{
    int x , y , c ; 
};
map <pair<int,int> , bool >vis ;
bool valid (int r ,int c )
{
    if (r < 1 || r > 1e9 || c < 1 || c > 1e9 || vis[{r,c}] || !SZ(ROW[r]) )return false ; 
    for (int i =0 ; i < SZ(ROW[r]) ;i++)
    {
        if (c >= ROW[r][i].f && c <= ROW[r][i].s )
            break; 
        if (i+1 == SZ(ROW[r]))
            return false ; 
    } 
    return vis[{r,c}] =1 ; 
}
int main ()
{
    pair <int,int> fr , to ; 
    int n ; 
    scanf ("%d%d%d%d%d" , &fr.f , &fr.s , &to.f , &to.s ,&n );
    for (int i =0 ; i < n ;i++)
    {
        int r ,  x , y ; 
        scanf ("%d%d%d" , &r , &x , &y ); 
        ROW [r].pb({x,y}); 
    }
    
    queue <node> b ; 
    b.push({fr.f,fr.s,0}); 
    int ans =-1 ; 
    while (!b.empty())
    {
        node t = b.front() ;
        b.pop(); 
        int x[] ={1,-1,0,0,1,1,-1,-1}; 
        int y[] ={0,0,1,-1,1,-1,1,-1};
        if (t.x == to.f && t.y == to.s )
        {
            ans = t.c ; 
            break; 
        }
        for (int i =0 ; i < 8 ;i++)
        {
            int tx = x[i]+t.x ; 
            int ty = y[i]+t.y ; 
            if (valid(tx,ty))
            {
                b.push({tx,ty,t.c+1});
            }
        }
    }
    printf ("%d\n" , ans ); 
    return 0 ; 
}
