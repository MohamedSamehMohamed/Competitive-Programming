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
int a [100][2],n,ans=-1; 
bool vis[100];
void DFS (int node )
{
    vis[node] = 1;  
    for (int i =0 ; i < n ;i++)
    {
        if (vis[i])continue ; 
        if (a[node][0] == a[i][0] || a[node][1] == a[i][1])
            DFS(i); 
    }
}
int main ()
{   
   cin >> n ; 
   for (int i =0 ; i < n ;i++)
       cin >> a[i][0] >> a[i][1] ;
   for (int i =0;  i< n ;i++)
   {
       if (!vis[i])
           DFS(i),ans++;
   }
   cout << ans <<"\n";
    return 0 ; 
}