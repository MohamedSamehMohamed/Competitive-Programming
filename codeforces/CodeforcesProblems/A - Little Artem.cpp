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
    int t; 
    cin >> t ;
    while (t--)
    {
        int n,m;
        cin >> n >> m ;
        for (int i =0 ; i < n ;i++)
        {
            for (int j =0 ; j < m ;j++)
            {
                if (i == j && i == 0 )cout <<"W";
                else 
                cout <<"B"; 
            }
            cout <<"\n"; 
        }
    }
}
