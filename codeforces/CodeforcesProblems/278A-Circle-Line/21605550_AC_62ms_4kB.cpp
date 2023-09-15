// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int n ;
int s , e ;
int a[100];
int main()
{
scanf ("%d" ,&n );
for (int i =0 ; i < n ;i++)scanf ("%d" , a+i);
scanf ("%d%d", &s ,&e );
s--;
e--;
int cur = s ;
int ans =0 ;
while (cur != e )
{
    ans += a[cur];
    cur = (cur + 1 )%n ;
}
cur = s ;
int ans0 =0;
while (cur != e )
{
    int p = (cur - 1 + n )%n ;
    ans0 += a[p];
    cur = p ;
}
cout << min (ans , ans0 )<<"\n";
}
