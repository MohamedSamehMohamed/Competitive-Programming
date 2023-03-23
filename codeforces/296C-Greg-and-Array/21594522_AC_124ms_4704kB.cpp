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
ll a[100002];
ll op[100002][3];
ll fin[100002];
ll simi[100002];
int main()
{
    int n , m , k ;
    scanf ("%d%d%d" , &n ,&m ,&k);
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%lld" ,a+i );
    }
    for (int i =0 ; i < m ;i++)
    {
        scanf ("%lld%lld%lld" , &op[i][0] , &op[i][1] , &op[i][2]);
        op[i][0]--;
        op[i][1]--;
    }
    for (int i =0 ; i < k ;i++)
    {
        int l , r;
        scanf ("%d%d" , &l ,&r);
        l--;
        r--;
        fin[l]++;
        fin[r+1]--;
    }
    for (int i = 1; i < m ;i++)
        fin[i] += fin[i-1];
    for (int i = 0 ; i < m ;i++)
    {
        simi[  op[i][0] ] += op[i][2] * fin[i];
        simi[ op[i][1] + 1  ] -= op[i][2] * fin[i];
    }
    for (int i =1 ; i < n ;i++)simi[i] += simi[i-1];
    for (int i =0 ; i < n ;i++)
    {
        printf ("%lld " , a[i] + simi[i] );
    }


}
