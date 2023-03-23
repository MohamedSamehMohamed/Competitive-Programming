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
int main()
{
    cin >> n >> k ;
    string x[n] ;
    string y[n] ;
    for (int i =0 ; i < n ; i++)cin >> x[i];
    int a[k];
    for (int i =0 ; i < k ;i++)a[i] = i ;
    int mn = 1e9 ;
    do
    {
        for (int i =0 ; i < n ;i++)
        {
            y[i] = "";

            for (int j =0 ; j < k ;j++){
                    y[i]+=x[i][ a[j] ];
                //cout << a[j] <<" " << x[ a[j] ]
            }
        }
        int mns , mx ;
        mns = 1e9 ;
        mx =0 ;
        for (int i =0 ; i < n ;i++)
        {
            mns = min (mns , atoi(y[i].c_str()));
            mx = max (mx , atoi(y[i].c_str()));

        }
        //cout << mx <<" " << mns <<"\n";
        mn = min (mn , mx - mns );
    }while (next_permutation(a,a+k));
    cout << mn <<"\n";
}
