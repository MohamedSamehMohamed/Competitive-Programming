// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std ;

typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
bool vis [10001]; 
int n , e , con ;
vector <vector<int>>G(10001);
void conected (int node )
{
	vis[node]=1; 
	for (int i =0 ; i < G[node].size();i++)
	{
		if ( !vis[G[node][i]] )
			conected(G[node][i]);
	}
}
int main ()
{
	 
	cin >> n >> e;  
	for (int i =0 ; i < e ;i++)
	{
		int u , v ; 
		cin >> u >> v ; 
		G[u].pb(v); 
		G[v].pb(u); 
	}	
	for (int i = 1; i <= n ;i++)
	{
		if (!vis[i])
		{
			con++; 
			conected(i); 
		}
	}
cout << (n-e==1&&con==1?"YES\n" : "NO\n");
return 0; 
}
