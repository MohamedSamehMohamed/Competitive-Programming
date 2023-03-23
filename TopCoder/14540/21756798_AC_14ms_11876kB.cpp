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
class SafeBetting
{
public :
int minRounds(int a, int b, int c)
{
    int ans =0 ;
    while (b < c )
    {
        ans ++;
        b += ( b - a ) ;
    }
    return ans ;
}
};
