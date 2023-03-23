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
#include <cstring>
#include <iomanip>    
using namespace std ;
typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
void READ (string INPUT = "NO" , string OUTPUT = "NO" )
{
    if (INPUT != "NO")
    freopen(INPUT.c_str() , "r" , stdin );
    if (OUTPUT!="NO")
    freopen ( OUTPUT.c_str() , "w" , stdout);
}
bool siev[3001];
int n ;
vector <int> ans ;  
int main ()
{
    siev[0] = siev[1] =1 ;
    for (int i = 2; i * i <= 3001 ;i++)
        if (!siev[i])
        for (int j = i*2 ; j < 3001 ;j+=i)
            siev[j] =1 ; 
    
    for (int i = 2;i <= 3000 ;i++)
    {
        map <int,bool> mp ;
        for (int j = 1; j *j <= i ;j++)
        {
            if (i%j==0)
            {
                if (!siev[j])
                    mp[j]=1; 
                if (!siev[i/j])
                    mp[i/j]=1; 
            }
        }
        if (SZ(mp)==2)
            ans.pb(i);
    }
    int n ;
    cin >> n; 
    int l =0 , r = SZ(ans)-1,m,j=0 ;
    while (l<=r)
    {
        m = (l+r)>>1; 
        if (ans[m] <= n)
            j = l = m+1; 
        else 
            r = m-1;
    }
    cout << j <<"\n";
   return 0 ; 
}
