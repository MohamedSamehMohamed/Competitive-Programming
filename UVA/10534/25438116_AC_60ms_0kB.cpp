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
int n;
int idx;
const int M = 1e4 + 1; 
int a[M];
int LIS[M]; 
int LDS[M]; 
stack<int> sk[M]; 
int FindIndx (int x)
{
    int l = 0 , r = idx , m , ans = -1 ;
    while (l <= r )
    {
        m = (l+r)>>1; 
        if (sk[m].top() >= x )
        {
            ans = m;
            r = m-1 ;
        }else 
        l = m+1 ;
    }
    return ans ;
}
void FindLIS()
{
    for (int i =0 ; i < n ;i++)
    {
        while (!sk[i].empty())sk[i].pop();
        LIS[i] = 0;
    }
    LIS[0] = 1; 
    idx =0 ;
    sk[idx].push(a[0]);
    int mxinsk =0 ;
    for (int i = 1 ; i < n ;i++)
    {
        int curidx = FindIndx(a[i]);
        if (curidx == -1 )
        {
            idx++;
            sk[idx].push(a[i]);
            mxinsk = max (mxinsk , SZ(sk[idx])); 
        }else 
        {
            sk[curidx].push(a[i]); 
            mxinsk = max (mxinsk , SZ(sk[curidx])); 
        }
        LIS[i] = idx + 1  ;
        
    }

}
void FindLDS()
{
    for (int i =0 ; i < n ;i++)
    {
        while (!sk[i].empty())sk[i].pop();
        LDS[i] = 0;
    }
    LDS[n-1] = 1; 
    idx =0 ;
    sk[idx].push(a[n-1]);
    int mxinsk =0 ;
    for (int i = n-2 ; ~i ;i--)
    {
        int curidx = FindIndx(a[i]);
        if (curidx == -1 )
        {
            idx++;
            sk[idx].push(a[i]);
            mxinsk = max (mxinsk , SZ(sk[idx])); 
        }else 
        {
            sk[curidx].push(a[i]); 
            mxinsk = max (mxinsk , SZ(sk[curidx])); 
        }
        LDS[i] = idx+1  ;
    }
}
void test ()
{
    for (int i =0 ; i < n ;i++)
    {
        scanf("%d" ,a+i);
    }
    FindLIS();
    FindLDS(); 
    int ans =0 ;
    for (int i =0 ; i < n ;i++)
    {
        ans = max (ans , 2 * min (LIS[i] , LDS[i] ) - 1  );
    }
    printf ("%d\n" , ans );

}
int main ()
{
    while (scanf("%d" , &n ) == 1 )
    test();
}