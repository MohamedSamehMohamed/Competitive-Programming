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
int d , sum ;
int ans[30];
int lim[30][2];
int main()
{
scanf ("%d%d" , &d , &sum );
int cur =0;
for (int i =0 ; i < d ;i++)
{
    scanf ("%d%d" , &lim[i][0] , &lim[i][1]);
    cur += lim[i][0];
    ans[i] = lim[i][0];
}
while (cur < sum )
{
    bool ch =0 ;
    for (int i =0 ; i < d ; i++)
    {
        if (ans[i] == lim[i][1] )continue ;
        while (cur < sum && ans[i] < lim[i][1] )
        {
            ch = 1 ;
            ans[i]++;
            cur++;
        }
    }
    if (!ch)break;
}
if (cur == sum )
{
    printf ("YES\n");
    for (int i =0 ; i < d ;i++)printf ("%d ", ans[i]);
}else
printf ("NO\n");
}
