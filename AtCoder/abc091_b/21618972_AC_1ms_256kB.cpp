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
int main()
{
    int n , m ;
    scanf ("%d" , &n );
    string x[n];
    for (int i =0 ; i < n ;i++)cin >> x[i];
    scanf ("%d" , &m );
    string y[m];
    for (int i =0 ; i < m ;i++)cin>>y[i];
    map <string , int > frq ;

    for (int i =0 ; i < n ;i++)frq[ x[i] ]++;
    for (int i =0 ; i < m ;i++)frq[ y[i] ]--;
    int best =  0 ;
    for (auto S : frq )best = max (best , S.s );
    cout << best <<"\n";
}
