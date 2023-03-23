// Author : Not Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
ll n,t,c,s[2];
vector<ll>a[2];
int main ()
{
cin>>n;
	a[0].pb(0);
	a[1].pb(0);
	while(n--){
        cin >> c ;
		t=c<0;
		a[t].pb(abs(c));
		a[t][0]+=abs(c);
	}
	a[t].pb(1);
	cout<< (a[0]>a[1]?"first":"second");



   return 0 ;
}


