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
int T , N , H ; 
set <string> ans ; 
void gen (int h , string a )
{
    if (SZ(a) > N )return ; 
    if (h > H )return ;
    if (SZ(a) == N && h == H )
    {
        ans.insert(a); return; 
    }
     
    if (h == H )
        gen(h,a+'0'); 
    else
    {
        gen(h+1,a+'1'); 
        gen(h,a+'0'); 
    }
        
    
}
int main ()
{   
    cin >> T ; 
    while (T--)
    {
        scanf ("%d%d" , &N , &H ); 
        gen(0,"");
        
        for (auto a : ans )
        {
            cout << a <<"\n"; 
        }
        if (T)
        cout <<"\n"; 
        ans.clear();
    }
     
    return 0 ; 
}
