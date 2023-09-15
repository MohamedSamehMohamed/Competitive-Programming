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
const int M = 2e5 + 9;
int a[M];
int frq[M];
int t, n;
vector<pair<int,int>> ans ;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t ;
    while (t--)
    {
        ans.clear(); 
        int mx =0;
        cin >> n ;
        for (int i =0 ; i <= n ;i++)frq[i]=0; 
        bool can = 1 ;
        for (int i =0 ; i < n ;i++)
        {
            cin >> a[i];
            mx = max (mx , a[i]);
            frq[ a[i] ]++;
            if (frq[ a[i] ] > 2 )can = 0;
        }
        if (!can)
        {
            cout <<"0\n"; 
            continue ; 
        }
        int idx = 0; 
        while (idx <= n && frq[idx+1] == 2)
        {
            idx++; 
        }
        if (idx == 0 )
        {
            cout <<"0\n"; 
            continue; 
        }
        int nxt = idx + 1 ;
        while (nxt <= n && frq[nxt] == 1 )
        {
            nxt++; 
        }
        nxt--; 
        if (nxt != mx )
        {
            cout <<"0\n"; 
            continue ;
        }
        int len = nxt - idx ; 
        memset(frq, 0 , sizeof frq);
        int fi = idx ; 
        ll sum = (1LL*idx * (idx+1))/2 ;
        idx += len ; 
        ll sum2 = (1LL*idx*(idx+1))/2 ; 
        ll cur =0 ;
        int dif = 0;
        for (int i =0 ; i < n ;i++)
        {
            cur += a[i];
            if (++frq[ a[i] ] == 1 )dif++; 
            if ((cur == sum && dif == fi ) || (cur == sum2&&dif == idx ) )
            {
                ans.pb({i+1 , n - i-1 });
            }
        }
        cout << SZ(ans) <<"\n"; 
        for (auto i : ans )
        cout << i.f <<" " << i.s <<"\n"; 
    }
 
}
