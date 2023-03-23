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
int n , k ;
string x ;
int main()
{
    cin >> n >> k >> x ;
    int ans =0 ;
    if (k == 2 )
    {
        string y ,z ;
        y = z = "";
        for (int i =0 ; i < n ;i++)y+=(i % 2 ? 'A' : 'B'),z+=(i % 2 ? 'B' : 'A');
        int t =0 ;
        int t1 =0 ;
        for (int i =0 ; i < n ;i++)
        {
            if (x[i] != z[i])t1++;
            if (x[i] != y[i])t++;
        }
        if (t < t1 )
        {
            x = y ;
            ans = t ;
        }else
        {
            x = z ;
            ans = t1 ;
        }


    }else
    {
        for (int i =1 ; i  < n ; i++)
        {
            if (x[i] == x[i-1])
            {
                for (int j =0 ; j < k ;j++)
                {
                    if (char ('A' + j) != x[i-1] && ( i+1 == n || (char ('A' + j) != x[i+1]) ) )
                    {
                        x[i] = char('A' + j );
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans <<"\n" << x <<"\n";
}
