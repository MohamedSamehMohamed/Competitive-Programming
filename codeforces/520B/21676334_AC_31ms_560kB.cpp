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
    int a, b;
    scanf ("%d%d" , &a ,&b );
    queue <pair<int,int>> q ;
    q.push({a , 0 });
    map <int ,bool >mp;
    while (!q.empty())
    {
        pair<int,int> cur = q.front() ;
        q.pop();
        if (cur.f == b )
        {
            printf ("%d\n" , cur.s );
            break ;
        }
        if (cur.f > b )
        {
         if (cur.f > 0 &&mp.find(cur.f-1) == mp.end())
         {
             mp[cur.f-1] =1 ;
             q.push({cur.f-1 , cur.s+1});
         }
        }else
        {
            if (mp.find(cur.f-1)== mp.end() && cur.f - 1 > 0 )
            {
                mp[cur.f-1] =1 ;
                q.push({cur.f-1 , cur.s+1});
            }
            if (mp.find(1LL*cur.f*2) == mp.end() && 1LL*cur.f * 2 < 1e8 )
            {
                mp[cur.f*2] = 1;
                q.push({cur.f*2 , cur.s + 1});
            }
        }
    }
}
