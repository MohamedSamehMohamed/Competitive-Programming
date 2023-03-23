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
int n ;
bool siev[1001];
bool pf (int x )
{
    set <int> pp ;
    for (int i =2;x != 1 &&  i < 1001 ; i++)
    {
        if (siev[i])continue ;
        while (x % i ==0)
        {
            x/=i;
            pp.insert(i);
        }
    }
    return pp.size() == 1 ;
}
int main()
{
    for (int i =2 ; i < 1001 ;i++)
    {
        if (siev[i])continue ;
        for (int j = i*i ; j < 1001 ;j+=i)
            siev[j] =1 ;
    }
    scanf ("%d" ,&n );
    if (n == 1 )
    {
        printf ("0\n");
        return 0;
    }
    set <int> ans ;
    for (int i = 2; i <= n ;i++)
    {
        if (siev[i])continue ;
        ans.insert(i);
        int cur = 2*i ;
        while (cur <= n )
        {
            if (pf(cur))
            ans.insert(cur);
            cur += i ;
        }
    }
    printf ("%d\n" , SZ(ans));
    for (auto s : ans )cout << s <<" ";

}
