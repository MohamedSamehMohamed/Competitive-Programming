// Author : Mohamed Sameh
#include<bits/stdc++.h>
//#include<iostream>
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
vector <int> Divisors ; 
map<int,bool>mp; 

int a , b , q ;
void getdiv(int num )
{
	for (int i =1 ; i*i <= num ; i++)
	{
		if (num%i==0)
		{
				if (!mp[i] && a %i == 0 && b%i==0 )
				{
					Divisors.pb (i); 
					mp[i]=1; 
				}
			if (num/i != i && !mp[num/i] && a%(num/i) == 0 && b%(num/i) == 0)
			  {
				  mp[num/i]=1; 
				  Divisors.pb (num/i); 
			  }
		}
	}
}
int ans (int lo , int hi)
{
	int l =0 , r = Divisors.size()-1,m , j =-1;
	while (l<=r)
	{
		m = (l+r)>>1; 
		if ( Divisors[m] <= hi && Divisors[m] >= lo )
			{
				j =  Divisors[m];
				l = m+1;  
			}
		else if (Divisors[m] > hi)
			r = m-1; 
		else 
			l = m+1; 
	}
	return j ; 
}
int main ()
{ 
	a = ReadInt(); 
	b = ReadInt();
	q = ReadInt(); 
getdiv(a); 
getdiv(b);
sort(all(Divisors)); 
for (int i =0 ; i < q ; i++) 
{
	int l , r ; 
	l = ReadInt();
	r = ReadInt();
	printf("%d\n" , ans(l,r));  
}
return 0; 
}