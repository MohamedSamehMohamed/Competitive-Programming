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
using namespace std ;


typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()  
int a[101];
int b[101];
int id ; 
int n   ;
ll ans ; 
int main ()
{
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> a[i] ;
	for (int i=1 ;i < n;i++)
		a[i]+=a[i-1]; 
	
	for (int i=1;i<n;i++)
	{
		//cout << a[i-1] << " "<<a[n-1]-a[i-1] << "\n";
		if (a[i-1] >= 1 && a[n-1] - a[i-1] >= 1 )
			{
				b[a[i-1]]++;
				id = max (id , a[i-1]);
			}
	}
	ans =1 ;
	for (int i=0;i<=id;i++)
		{
			if (b[i]!=0)
			ans*=b[i]; 
		}
	if (n==1)
	ans = a[0];
	for (int i=0;i<n;i++)
		if (a[i] != 0 )
			break;
		else if (i+1 == n)
			ans = 0;
	cout << ans <<"\n";
	
	
	
	return 0;
}

 