// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

int a[100009], n, i ;

ll k, t ;

int main ()
{
cin >> n >> k;
for( ; i < n; ++i )
		cin >> a[i];

sort( a, a + n );

--k ;
	for( i = 0; i < n; i += t ){
		
		for ( t = 1; a[i] == a[i + t]; ++t );
			if ( t * n > k )
				break; 
				
				k -= t * n ;
	}
	cout << a [i] << " " << a[k/t] << "\n";


   return 0 ;
}