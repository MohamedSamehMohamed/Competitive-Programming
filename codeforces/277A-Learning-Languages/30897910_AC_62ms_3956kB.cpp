#include<bits/stdc++.h>
//#include "LinkedList.h"
//#include"BinaryTree.h"
using namespace std ;

/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                           MOHAMED SAMEH                             #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
typedef long long ll ;
////////////////////////////////////////////////////////////////////
#define pf push_front
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define M_P make_pair
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
vector <vector <int> >G(202);
bool vis [202] ;
void  dfs (int  i )
{
vis[i]=1 ;
for (int j =0 ; j <  G[i].size() ; j++)
    {
        int node = G[i][j];
        if (  !vis [ node ] )
        {

            dfs(node);
        }
    }
}
int main ()
{
    int n , m ,t,t1 ,ans   ;
    cin >> n >> m ;
    bool done = 0 ;
    for (int i =0 ;i < n ;i++)
    {
        cin >> t ;
        if (t > 0 )
            done =1 ;
        for (int l =0 ; l < t ; l++)
        {
            cin >> t1 ;
            G[i].pb(t1+n);
            G[n+t1].pb(i);
        }
    }

    ans =( done  ?-1:0 )  ;



    for (int i = 0 ; i < n  ; i++ )
      {
            if (!vis[i])
            {
                dfs(i);
                ans++;
            }

      }
cout << ans << "\n";
    return 0;
}