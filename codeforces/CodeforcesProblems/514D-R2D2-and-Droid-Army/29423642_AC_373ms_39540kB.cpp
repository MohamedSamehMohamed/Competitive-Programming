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
int n, m, k, len, sum;
const int Lg = 20 ;
const int M  = 1e5 ;
int spt[M][5][Lg]; 
int LOG[M+1];
int mxq[5];
int Ans[5];
void buildSparse()
{
    for (int i = 2; i <= M ;i++)
    {
        LOG[i] = LOG[i/2] + 1 ;
    }
    for (int lg = 1; lg < Lg ;lg++)
        for (int j =0 ; j < m ;j++)
        {
            for (int i =0 ; i + (1<<lg) <= n ;i++)
            {
                spt[i][j][lg] = max( spt[i][j][lg-1] , spt[i + (1<<(lg-1))][j][lg-1]);
            }
        }
}
void Maxquery (int l, int r)
{
    int sz = LOG[r - l + 1 ];
    sum=0;
    for (int i =0; i < m ;i++)
    {
        mxq[i] = max(spt[l][i][sz],spt[r-(1<<sz)+1][i][sz]);
        sum += mxq[i]; 
    }
}
void BS(int L)
{
    int l = L ,  r = n-1 ,mid,ans=-1;
    while (l <= r )
    {
        mid = (l+r)>>1;
        Maxquery(L,mid);
        if (sum <= k )
        {
            ans = mid ;
            l = mid+1 ; 
        }else 
        r = mid-1 ; 
    }
    if (ans == -1 )return ;
    if (ans - L + 1 > len )
    {
        Maxquery(L,ans); 
        len = ans - L + 1 ;
        for (int i =0 ; i < m ;i++)
        Ans[i] = mxq[i];
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            cin >> spt[i][j][0]; 
        }
        
    }
    buildSparse();
    for (int i =0 ; i < n ;i++)
    {
        BS(i); 
    }
    for (int i =0 ; i < m ;i++)
    {
        cout << Ans[i] <<" \n"[i+1==m];
    }
}