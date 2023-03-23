
// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair <int,int> P2i ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
///#Read And Write  From File
/*

freopen("fruits.in","r",stdin);
freopen("out.txt","w",stdout);

*/

inline int ReadInt ()
{
int t ;
scanf ("%d", &t) ;
return t ;
}
inline void Print (int t )
{
printf("%d\n",t); 
}
ll a [100009];
int n , c ,t  , Ans;
bool Ok (ll &d )
{
	int C = c-1 ;
	for (int i =0 ; i < n ; )
	{
		int l , r , m , next =-1 ; 
		l = i+1;
		r = n-1; 
		while (l<=r)
		{
			m = (l+r)>>1; 
			if ( (a[m] - a[i]) >= d  )
			{
				next = m ; 
				r = m-1; 
			}else 
			l = m+1; 
		}
		if (next == -1 )
			return false ; 
		i = next ; 
		C--; 
		if (C==0)return true ; 
	}
	return (C == 0) ; 
}
int main ()
{
cin >> t ; 
while (t--)
{
cin >> n >> c ; 
for (int i =0 ; i < n ;i++)
{
	cin >> a[i]; 
}
sort(a,a+n); 
ll l , r , m ; 
l = 1 , r = 1e13; 
while (l<=r)
{
	m = (l+r)>>1LL;
	if (Ok(m))
	{
		// Can Be Put Caws with min-distance m ,, Try to make m big 
		Ans = m; 
		l= m+1; 
	}else 
	{
		// Can't be put ,, try less than m 
		r = m-1; 
	}
}

cout << Ans <<"\n"; 
}
return 0 ; 

}

