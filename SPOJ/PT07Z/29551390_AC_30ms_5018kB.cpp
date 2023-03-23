// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std ;

typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
vector <vector<int>> G(10001); 
bool vis [10001]; 
int n , root ,ans  ; 
void dfs (int r , int cost )
{
	vis[r]=1; 
	if (cost > ans )
	{
		ans = cost ; 
		root =r ;
	}
	for (int i =0 ; i < G[r].size();i++)
	{
		if ( !vis[G[r][i]] )
		{
			dfs(G[r][i] , cost + 1 );
		}
	}
}
int main ()
{
cin >> n ; 
for (int i =1 ;i < n ;i++)
{
	int u , v ; 
	cin >> u >> v ; 
	G[u].pb(v); 
	G[v].pb(u); 
}   
dfs(1,0); 
for (int i =0 ; i < 10001;i++)vis[i]=false ; 
dfs(root,0);
cout << ans <<"\n";
return 0; 
}
