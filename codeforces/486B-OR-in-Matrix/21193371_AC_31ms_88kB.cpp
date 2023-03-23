// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
int a[100][100];
int ans[100][100];
int n , m ;
bool setz (int r , int c )
{
    for (int i = 0 ; i < n ; i++)if (ans[i][c] == 1 )return false ;
    else
        ans[i][c] = 0 ;
    for (int i =0 ; i  < m ;i++)if (ans[r][i] == 1 )return false ;
    else
        ans[r][i] = 0 ;
    return true ;
}
bool SetO (int r , int c )
{
    for (int i = 0 ; i < n ; i++)if (ans[i][c] == 1 )return true ;
    else {
        if (ans[i][c] == -1 ){
        ans[i][c] = 1 ;
        return true ;
        }
    }
    for (int i =0 ; i  < m ;i++)if (ans[r][i] == 1 )return true ;
    else {
        if (ans[r][i] == -1  ){
        ans[r][i] = 1 ;
        return true ;
        }
    }
    return false ;
}
int main ()
{
    memset (ans , -1 ,sizeof ans );
    cin >> n >> m ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
            cin >> a[i][j];
    }
    for (int i =0 ; i < n;i++)
        for (int j =0 ; j < m ;j++)
    {
        if (a[i][j] == 0 )
        {
            if (!setz(i , j ))
            {
                cout <<"NO\n";
                return 0 ;
            }
        }
    }
    for (int i =0 ; i < n;i++)
        for (int j =0 ; j < m ;j++)
    {
        if (a[i][j])
        {
            if (!SetO(i , j ))
            {
                cout <<"NO\n";
                return 0 ;
            }
        }
    }
    cout <<"YES\n";
    for (int i =0 ; i < n ;i++)
        for (int j =0 ; j <  m ;j++)
            if (ans[i][j] == -1 )ans[i][j] = 0;
    for (int i=0  ; i < n ;i++)
        for (int j =0 ;j < m ;j++)
            cout << ans[i][j] <<" \n"[j + 1 == m ];
    return 0;
}
