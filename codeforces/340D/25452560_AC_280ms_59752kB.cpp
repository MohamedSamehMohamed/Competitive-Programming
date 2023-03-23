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
int idx;
const int N = 1e5 ;
stack<int> sk[N];
int a[N];
int n;
int FindIndx (int x)
{
    int l = 0 , r = idx , m , ans = -1 ;
    while (l <= r )
    {
        m = (l+r)>>1;
        if (sk[m].top() > x )
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
    idx =0 ;
    sk[idx].push(a[0]);
    for (int i = 1 ; i < n ;i++)
    {
        int curidx = FindIndx(a[i]);
        if (curidx == -1 )
        {
            idx++;
            sk[idx].push(a[i]);
        }else
        {
            sk[curidx].push(a[i]);
        }
    }
    cout << idx+1 <<"\n";

}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n ;
    for (int i =0; i < n ;i++)
    {
      cin >> a[i];
    }
    FindLIS();
}
