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
int a[100]; 
int mp[500];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t ;
    cin >> t ;
    while (t--)
    {
        int n, x ;
        cin >> n >> x ;
        for (int i =0 ; i < n ;i++)
        cin >> a[i];
        memset(mp,0,sizeof mp);
        for (int i =0 ; i < n ;i++)
        {
            mp[ a[i] ]=1;
        }
        for (int i = 1; x != 0 ;i++)
        {
            if (mp[i] == 0 )
            {
                x--; 
                mp[i]=1; 
            }
        }
        int ans = 0;
        for (int i =1;mp[i];i++)
        {
            ans = i ;
        }
        
        cout << ans <<"\n"; 
    }
}
