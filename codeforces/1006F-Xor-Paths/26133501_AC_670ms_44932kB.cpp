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
int n , m ,half;
ll a[20][20];
map<ll,int> mp[20][20];
ll ans ,k;
void DownRight (int i , int j , ll Xor , int d  )
{
    Xor ^= a[i][j];
    if (d == half)
    {
        mp[i][j][Xor]++;
        return ;
    }
    if (i+1 < n )DownRight(i+1 , j , Xor , d +1 );
    if (j+1 < m )DownRight(i , j+1 , Xor , d + 1 );
}
void UpLeft (int i , int j , ll Xor , int d )
{
    Xor ^= a[i][j];
    if (d == n+m-2-half)
    {
        Xor ^= a[i][j];
        ans += mp[i][j][Xor ^ k];
        return ;
    }
    if (i - 1 >= 0 )UpLeft(i-1,j,Xor,d+1);
    if (j - 1 >= 0)UpLeft(i,j-1,Xor,d+1);
}
int main()
{
    cin >> n >> m >> k ;
    for (int i =0 ; i < n ;i++)
        for (int j =0 ; j < m ;j++)
            cin >> a[i][j];
    half = (n+m-2)>>1 ;
    DownRight(0,0,0,0);
    UpLeft(n-1,m-1,0,0);
    cout << ans <<"\n";

}