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
int n ;
string x , y ;
int pre[100001][4];
int main()
{
    cin >> n >> x >> y ;
    for (int i =0 ; i < n ;i++)
    {
        pre[i+1][0] += (x[i] == '0' && y[i] == '0') + pre[i][0];
        pre[i+1][1] += (x[i] == '0' && y[i] == '1') + pre[i][1];
        pre[i+1][2] += (x[i] == '1' && y[i] == '0') + pre[i][2];
        pre[i+1][3] += (x[i] == '1' && y[i] == '1') + pre[i][3];
    }
    ll ans =0 ;
    for (int i  =0 ; i < n ;i++)
    {
        if (x[i] == y[i] && x[i] == '0')
        {
            ans += (pre[n][2] - pre[i][2]) + (pre[n][3] - pre[i][3]);
        }else if (x[i] == y[i] && x[i] == '1')
        {
            ans += pre[n][0] - pre[i][0];
        }else if (x[i] == '0')
        {
            ans += pre[n][2] - pre[i][2];
        }else
        {
            ans += pre[n][0] - pre[i][0];
            ans += pre[n][1] - pre[i][1];
        }
    }
    cout << ans <<"\n";
}
