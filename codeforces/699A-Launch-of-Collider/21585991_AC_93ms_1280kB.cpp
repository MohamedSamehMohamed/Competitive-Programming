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
string x ;
int a[200000];
int main()
{
scanf ("%d" , &n );
cin >> x ;
for (int i =0; i < n ;i++)scanf ("%d" ,a+i);
int l = -1 ;
int ans =-1 ;
for (int i =0 ; i < n ;i++)
{
    if (x[i] == 'R')
    {
        l = i ;
    }
    if (l != -1 && x[i] == 'L')
    {
        if (ans == -1 )ans = (a[i] - a[l])/2;
        ans = min ( (a[i] - a[l])/2 , ans );
    }
}
printf ("%d\n" ,ans );

}
