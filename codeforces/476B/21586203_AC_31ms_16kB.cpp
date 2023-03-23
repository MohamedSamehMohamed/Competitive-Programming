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
string x , y ;
int main()
{
cin >> x >> y ;
int a , b ;
a = b = 0 ;
int p , m ;
p = m =0 ;
for (int i =0 ; i < SZ(x) ;i++)
{
    if (x[i] == '+')p++;
    else
        m++;
}
queue <pair<pair<int,int>, int >> q ;
q.push({{0,0} , 0 });
while (!q.empty())
{
    pair<int ,int > ret = q.front().f ;
    int id = q.front().s ;
    q.pop();
    if (id == SZ(x))
    {
        if (ret.f == p && ret.s == m )a++;
        b++;
        continue ;
    }
    if (y[id] != '?')
    {
        if (y[id] == '+')ret.f ++;
        else
            ret.s++;
        q.push({ret , id + 1 });
        continue ;
    }
    q.push({{ret.f +1 , ret.s },id + 1 });
    q.push({{ret.f , ret.s +1 },id +1 });
}
printf ("%.9f\n" , 1.0*a / b );

}
