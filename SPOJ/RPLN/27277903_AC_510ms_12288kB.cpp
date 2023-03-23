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
const int M  = 1e5 ;
const int Lg = 20  ;
int spt[M][Lg];
int n;
int a[M];
int LOG[M+1];
ll querySum (int l, int r)
{
    ll ans =0 ;
    for (int i = Lg - 1 ; i >= 0 ;i--)
    {
        if ( (1<<i) <=  (r - l + 1) )
        {
            ans += spt[l][i];
            l+=(1<<i);
        }
    }
    return ans ;
}
void ConstructForSumRange()
{
    for (int i =0 ; i < n ;i++)
    spt[i][0] = a[i];
    for (int p = 1; p < Lg ;p++)
    {
        for (int i =0 ; i + (1<<p) <= n;i++)
        {
            spt[i][p] = spt[i][p-1] + spt[i+(1<<(p-1))][p-1];
        }
    }
}
void ConstructForMaxRange()
{
    // if overlap doesn't affect the answer we can get the answer in O (1) time.
    LOG[1] = 0;
    for (int i = 2; i < M+1 ;i++)
    {
        LOG[i] = LOG[i/2] + 1 ;
    }
    for (int i =0 ; i < n ;i++)
    spt[i][0] = a[i];
    for (int p = 1; p < Lg ;p++)
    {
        for (int i =0 ; i + (1<<p) <= n;i++)
        {
            spt[i][p] = max(spt[i][p-1] , spt[i+(1<<(p-1))][p-1]);
        }
    }
}
int queryMax (int l, int r)
{
    int p = LOG[r - l + 1 ];
    return max (  spt[l][p] , spt[r - (1<<p) + 1 ][p] );
}
void ConstructForMinRange()
{
    // if overlap doesn't affect the answer we can get the answer in O (1) time.
    for (int i =0 ; i < n ;i++)
    spt[i][0] = a[i];
    for (int p = 1; p < Lg ;p++)
    {
        for (int i =0 ; i + (1<<p) <= n;i++)
        {
            spt[i][p] = min(spt[i][p-1] , spt[i+(1<<(p-1))][p-1]);
        }
    }

}
int queryMin (int l, int r)
{
    int p = LOG[r - l + 1 ];
    return min (  spt[l][p] , spt[r - (1<<p) + 1 ][p] );
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i < M+1 ;i++) LOG[i] = LOG[i>>1] + 1 ;
    int t;cin>>t;
    for (int it = 1; it <= t; it++)
    {
      cout << "Scenario #" << it<<":\n";
      int q;
      cin >> n >> q ;
      for (int i=0 ; i < n ;i++) cin >> a[i];
      ConstructForMinRange();
      while(q--)
      {
        int l, r;
        cin >> l >> r;l--;r--;
        if (l > r)swap(l, r);
        cout << queryMin(l, r) << '\n';
      }
    }
}
