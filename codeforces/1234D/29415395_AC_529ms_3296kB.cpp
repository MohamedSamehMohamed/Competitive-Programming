// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;
const int M = 5e5 + 9 ;
//int Tree[M]; 
string x ; 
set<int> st [26]; 
bool ok (int id ,int l , int r )
{
	 if (st[id].lower_bound (l) == st[id].end())return false ; 
	 int cur =  *st[id].lower_bound (l) ; 
	 if (cur >= l && cur <= r )return 1 ; 
	 return 0 ; 
}
int main ()
{
	cin >> x;  
	for (int i =0 ; i < SZ(x) ; i++)
	{
		st[ x[i] - 'a' ].insert(i);
	}
	int q ; 
	scanf ("%d" , &q ); 
	while (q--)
	{
		int l , r;  
		char c ; 
		int type ; 
		scanf ("%d" , &type ); 
		if (type == 1 )
		{
		 scanf ("%d %c" , &l , &c ); 
		 l--; 
		 st[x[l] - 'a'].erase(l); 
		 x[l] = c;
		 st[ c - 'a' ].insert(l); 
		}else 
		{
			scanf ("%d%d" , &l ,&r ); 
			l--; r--;
			int ans =0 ;   
			for (int i =0 ; i < 26 ;i++)
			{
				if ( ok( i , l , r ) )ans++; 
			}
			printf ("%d\n" , ans ); 
		}
	}
}	
 