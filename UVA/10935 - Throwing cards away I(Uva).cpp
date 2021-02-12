// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
    int n ;
    while (scanf ("%d" , &n) == 1 && n )
    {
        queue<int> q ;
        for (int i = 1; i <= n ;i++)q.push(i);
        vector<int> ans ;
        while (!q.empty() && SZ(q) > 1 )
        {
            ans.pb(q.front());
            q.pop();
            int x = q.front();
            q.pop();
            q.push(x);
        }
        printf ("Discarded cards:");
        if (SZ(ans))printf (" ");
        for (int i =0 ; i < SZ(ans) ;i++)
        {
            printf ("%d" , ans[i]);
            if (i + 1 < SZ(ans))
            {
                printf (", ");
            }
        }
        printf ("\n");
        printf ("Remaining card: %d\n" , q.front());
    }

}
