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
string x ;
int frq[26];
int main()
{
    cin >> x ;
    for (int i =0 ; i < SZ(x) ;i++)frq[ x[i] - 'a' ]++;
    int odd =0;
    for (int i =0 ; i < 26 ;i++)odd += (frq[i]%2);
    if ((SZ(x)%2 == odd % 2 && odd < 2) || SZ(x) % 2  )
    {
        printf ("First\n");
    }else
    {
        printf ("Second\n");
    }
}
