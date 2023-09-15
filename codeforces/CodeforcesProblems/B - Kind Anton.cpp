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
const int M =1e5 ;
int a[M];
int b[M]; 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t ;
    cin >> t ;
    while (t--)
    {
        int n;
        cin >> n ;
        for (int i =0 ; i < n ;i++)
        {
            cin >> a[i];
        }
        for (int i =0 ; i < n ;i++)
        {
            cin >> b[i];
        }
        bool ne , po ;
        ne = po = 0 ;
        bool ok = 1; 
        for (int i =0 ; i < n ;i++)
        {
            if (a[i] == b[i])
            {
                if (a[i] == 1 )po = 1;  
                else if (a[i] == -1)ne=1 ; 
                continue ; 
            }
            if (a[i] < b[i])
            {
                if (po == 0 )
                {
                    ok = 0;
                    break; 
                }
            }else 
            {
                if (ne == 0 )
                {
                    ok = 0;
                    break; 
                }
            }
            
            if (a[i] == 1 )po = 1;  
            else if (a[i] == -1)ne=1 ; 
                
        }
        if (ok)
        cout <<"YES\n"; 
        else 
        cout <<"NO\n"; 
    }
}
