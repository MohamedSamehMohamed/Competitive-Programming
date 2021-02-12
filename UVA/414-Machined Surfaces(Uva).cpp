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
    int n;
    while (scanf ("%d" , &n) == 1 && n )
    {
        vector<int> v;
        string x ;
        while (n--)
        {
            x = "";
            while (SZ(x) == 0)
            getline(cin ,x);
            int val =0 ;
            for (int i =0 ; i < SZ(x) ;i++)
            {
                val += (x[i] == 'X');
            }
            v.pb(25 - val);
        }
        sort(all(v));
        int ans =0 ;
        for (int i =1 ; i < SZ(v);i++)
        {
            v[i]-=v[0];
            ans += v[i];
        }
        printf ("%d\n" ,ans);
    }
}
