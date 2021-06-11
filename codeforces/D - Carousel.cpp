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
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<int> old(n) ,ans(n); 
        int c = 1;
        int d = 0;
        for (int i =0 ; i < n ;i++)
        {
            cin >> old[i];
            if (i)d |= (old[i] != old[i-1]);  
        }
        if (!d)
        {
            cout << 1 <<"\n"; 
            for (int i =0 ; i < n ;i++)
            cout << 1 <<" "; 
            cout <<"\n"; 
            continue ; 
        }
        c = 2 ; 
        
        if (n & 1 && old[0] != old[n-1])
        {
            bool can =0;
            for (int i = 1; i < n ;i++)if (old[i] == old[i-1])
            {
                can = 1; 
                break; 
            }
            if ( !can ){
            c = 3;  
            ans[0] = 1 ;ans[n-1]=3;
            for (int i=1; i < n-1;i++)ans[i] = (ans[i-1]==1 ? 2 : 1); 
            }else 
            {
                ans[0]=1; 
                for (int i=1; i < n ;i++)
                {
                    if (old[i] == old[i-1] && can)ans[i] = ans[i-1],can=0; 
                    else 
                    ans[i] = (ans[i-1]==1 ? 2 : 1 ); 
                }
            }
        }else 
        {
            ans[0]=1;
            for (int i=1;  i < n ;i++)ans[i] = (ans[i-1] == 1 ? 2 : 1 ); 
        }
        cout << c <<"\n"; 
        for (int i =0 ; i < n ;i++)
        {
            cout << ans[i] <<" \n"[i == n-1];
        }
    }   
    
}
