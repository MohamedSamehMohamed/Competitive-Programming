// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
int n , m ;

int main ()
{
    cin >> n>> m ;
    if (n == m )
    {
        cout <<"0\n";
        return 0 ;
    }
    queue < pair<pair<int ,int > , int > > q ;
    q.push({{n,m} , 0 });
    map <pair<int,int>, int > vis ;
    int ans = -1;
    while (!q.empty())
    {
        pair<pair<int,int> ,int > tem  = q.front();
        q.pop();
        n = tem.f.f ;
        m = tem.f.s ;
        if (n == m )
        {
            ans = tem.s ;
            break;
        }
        if (n % 2 == 0 && vis.find({n/2,m}) == vis.end())
        q.push({{n/2 , m } , tem.s + 1}), vis[{n/2,m}] = 1;
        if (n % 3 == 0 && vis.find({n/3,m}) == vis.end())
        q.push({{n/3 , m} , tem.s + 1}) , vis[{n/3,m}] = 1 ;
        if (n % 5 == 0 && vis.find({n/5,m}) == vis.end())
        q.push({{n/5 , m } , tem.s + 1}) , vis[{n/5,m}] = 1;

        if (m % 2 == 0 && vis.find({n,m/2}) == vis.end())
        q.push({{n , m/2 } , tem.s + 1}), vis[{n,m/2}] = 1;
        if (m % 3 == 0 && vis.find({n,m/3}) == vis.end())
        q.push({{n , m/3} , tem.s + 1}) , vis[{n,m/3}] = 1 ;
        if (m % 5 == 0 && vis.find({n,m/5}) == vis.end())
        q.push({{n , m/5 } , tem.s + 1}) , vis[{n,m/5}] = 1;

    }
    cout << ans <<"\n";
     return 0;
}
