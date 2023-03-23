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
#include <sstream>
#include <string.h>
#include<fstream>
typedef long long ll ;
#define OO 2000000000
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf("%d" , &n )
void fo (){fflush(stdout);}
using namespace std;
int n , m ;
int Q [1001];
int mn[1001];  
int main()
{
	
	memset (mn , -1 , sizeof mn ); 
	scanf ("%d" , &n ); 
	for (int i =0 ;i < n;i++)
	{
		int qi ; 
		scanf ("%d" , &qi ); 
		Q[i+1] = qi ; 
	}
	scanf ("%d" , &m );  
	for (int i=0;i < m ;i++)
	{
		int a, b , c ; 
		scanf ("%d%d%d" , &a ,&b , &c );
		if (Q[a] <= Q[b])continue ; 
		if (mn[b] == -1 || mn[b] > c )mn[b] = c ; 
		
	}
	int take = 0 , ans =0 ;
	for (int i = 1 ; i <= n ;i++)
	{
		if (mn[i] != -1 )
		{ 
			take++; 
			ans += mn[i]; 
		}
	}
	if (take != n-1 )ans = -1; 
	printf ("%d\n" ,ans ); 
return 0;
}