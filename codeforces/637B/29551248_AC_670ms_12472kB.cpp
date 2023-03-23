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
map <string , bool >vis ; 
stack <string> chat ; 
int n ;
string x;  
int main ()
{
    cin >> n ; 
    for (int i =0 ; i < n ;i++)
    {
        cin >> x ; 
        chat.push(x); 
    }
    while (!chat.empty())
    {
        while (!chat.empty() && vis[chat.top()])chat.pop(); 
        if (!chat.empty())
        {
            cout << chat.top() <<"\n"; 
            vis[chat.top()] = 1;  
            chat.pop(); 
        }
    }


    return 0 ; 
}