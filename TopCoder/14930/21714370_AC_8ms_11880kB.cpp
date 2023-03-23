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
class BinaryCalculator
{
public :
    int minimumSteps(int a, int b)
    {
        map <int,bool> mp;
        queue <pair<int,int>> q ;
        q.push({a , 0 });
        while (!q.empty())
        {
            auto cur = q.front() ;
            q.pop();
            if (cur.f == b )
            {
                return cur.s ;
            }
            // -2 , +3
            if (mp.find(cur.f + 3 ) == mp.end())
            {
                q.push({cur.f + 3 , cur.s + 1 });
                mp[cur.f+3] = 1;
            }
            if (mp.find(cur.f - 2 ) == mp.end())
            {
                q.push({cur.f - 2 , cur.s + 1 });
                mp[cur.f-2] = 1;
            }

        }
    }
};
