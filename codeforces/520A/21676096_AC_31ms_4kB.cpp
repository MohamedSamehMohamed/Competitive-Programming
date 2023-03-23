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
    int n ;
    cin >> n ;
    string x ;
    cin >> x;
    map <char , bool >mp;
    for (int i =0 ; i < n ;i++)
    {
        if (x[i] < 'a')x[i] += 32 ;
        mp[ x[i] ] = 1;
    }
    if (SZ(mp) == 26 )printf ("YES\n");
    else
        printf ("NO\n");
}
