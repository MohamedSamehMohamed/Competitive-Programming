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
int a[2000];
int n ,  m ;
map <int,int> mp ;
int tar ()
{
    int best = 1;
    for (auto s : mp )
    {
        if (s.s < mp[best])best = s.f ;
    }
    return best ;
}
int mx ;
void change (int x , int rm)
{
    for (int i = 0 ;rm && i  < n ;i++)
    {
        if (a[i] == x )continue ;
        while ( mp [ a[i] ] > mx || a[i] > m  )
        {
            mp [ a[i] ]--;
            a[i] = x ;
            rm--;
            mp[ a[i] ]++;

        }
    }
}
int main()
{
    scanf ("%d%d" , &n ,&m);
    int ans = 0 ;
    for (int i =0 ; i < n ;i++)scanf ("%d" ,a+i);
    for (int i =0 ; i < n ;i++)
    {
        if (a[i] <= m )mp[a[i]]++;
    }
    mx = n / m ;
    for (int i =1 ; i <= m ;i++)
    {
        if (mp[i] >= mx )continue ;
        int rm = mx - mp[i];
        change (i , rm );
        ans += rm ;
    }
    cout << mx <<" " << ans <<"\n";
    for (int i =0 ; i < n ;i++)
    {
        cout << a[i] <<" ";
    }

}
