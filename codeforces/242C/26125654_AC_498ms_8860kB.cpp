// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
using namespace std ;


typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
map<int,vector<pair<int,int>>>Allaow ; 
map<pair<int,int> , bool >vis;
pair<int,int>from , to ;
int n , cost ;
int r , cl , cr ;
int mxc , mxr ;
bool allaow (int r , int c )
{
	for (int i =0 ; i < (int)Allaow[r].size();i++)
	{
		if (c >= Allaow[r][i].f && c <= Allaow[r][i].s )return true;
	}
	return false ;
}
bool valid (int r , int c )
{
	if (r > 0 && c > 0 && r < mxr && c < mxc && !vis[{r,c}] && allaow (r,c))
	{
		vis[{r,c}]=1; 
		return true ; 
	}
	return false ; 
}
int main ()
{
	scanf("%d%d%d%d%d" , &from.f ,&from.s ,&to.f ,&to.s , &n );
	
	for (int i =0 ;i<n;i++)
	{
		scanf("%d%d%d" , &r , &cl , &cr );
		Allaow[r].pb({cl,cr});
		mxc = max (mxc , cr );
		mxr = max (mxr,r );
	}
	mxc+=5;
	mxr+=5; 
	queue <pair< pair <int,int> , int >>BFS; 
	BFS.push({{from.f,from.s} , 0} ); 
	while (!BFS.empty())
	{
		from = BFS.front().f ; 
		cost = BFS.front().s ; 
		BFS.pop(); 
		if (from == to )
		{
			printf("%d\n" , cost); 
			return 0 ; 
		}
		int X []={-1,-1,0,0,1,1,1,-1};
		int Y []={0,1,-1,1,-1,0,1,-1};
		for (int i =0 ; i < 8 ;i++)
		{
			if (valid(from.f+X[i] , from.s + Y[i]))
				BFS.push({{from.f+X[i] , from.s+Y[i]} , cost+1 });
		}
		
	}
	cout << "-1\n";
return 0; 
}