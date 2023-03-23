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
bool Primes [10000] ; 
bool vis [10000]; 
void P ()
{
	Primes[0]=Primes[1]=1; 
	for (int i = 2 ; i * i <= 10000 ; i++)
	{
		if (!Primes[i])
		{
			for (int j = i*2 ;j < 10000 ; j+=i)
				Primes[j]=1; 
		}
	}
}
bool Four(int num )
{
	return (int)log10(num) + 1 == 4 ; 
}
void Reset ()
{
	for (int i =0 ; i <10000;i++)vis[i]=false ; 
}
void possibles(int cur ,queue<pair<int,int>> &BFS , int pos , int cost )
{
	
	
	int e = pow (10,pos);
	 
	int ret = cur%(e/10) ; 
	 
	cur = (cur/e)*e; 
	for (int i =0 ; i < 10 ;i++)
	{
		if (!vis[ret + cur+(i*(e/10))] && !Primes[ret + cur+(i*(e/10))]&&Four(ret + cur+(i*(e/10))))
		{
			BFS.push({ret + cur+(i*(e/10)),cost+1}); 
			vis[ret + cur+(i*(e/10))]=1; 
		}
	}
	 
}

int main ()
{
P(); 
int t ; 
cin >> t;  
while (t--)
{
	Reset(); 
	int from , to  ;
	bool ok = 0 ;  
	cin >> from >> to ; 
	if (Primes[from] || Primes[to] )
	{
		cout << "Impossible\n";continue ; 
	}
	queue<pair<int,int>> BFS ; 
	BFS.push({from,0});
	vis[from]=1; 
	while (!BFS.empty())
	{
		int cur = BFS.front().f ; 
		int cost = BFS.front().s ; 
		BFS.pop(); 
		if (cur == to )
		{
			cout << cost <<"\n"; 
			ok = 1 ; 
			break; 
		}
		possibles(cur,BFS,1,cost);
		possibles(cur,BFS,2,cost);
		possibles(cur,BFS,3,cost);
		possibles(cur,BFS,4,cost);
		
		
	}
	if (!ok)
	cout << "Impossible\n";
}
return 0; 
}
