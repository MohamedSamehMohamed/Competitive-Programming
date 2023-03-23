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
int n, c ,l,Lec,D;
const int MAX = 1001 ; 
int a[MAX];
int dp[MAX];
int dp1[MAX][MAX];
// max dis 250,000,000
int solve (int i= 0 )
{
    if (i == n)return 0;
    int &ret = dp[i];
    if (~ret)return ret ; 
    ret = 1e9 ;
    int rem = l ;
    while (i < n && rem >= a[i])
    {
        rem -= a[i];
        int Di ; 
        if (rem == 0 )Di = 0 ;
        else if (rem <= 10 )Di = -c ;
        else 
        Di = (rem-10) * (rem-10); 
        ret = min (ret , 1 + solve(i+1));
        i++;
    }
    return ret ; 
}
int solve1(int i =0 , int lec =0 )
{
    if (i == n)
    {
        if(lec == Lec)return 0;
        return 1e9;
    }
    int &ret = dp1[i][lec];
    if (~ret)return ret ; 
    ret = 1e9 ;
    int rem = l ;
    while (i < n && rem >= a[i])
    {
        rem -= a[i];
        int Di ; 
        if (rem == 0 )Di = 0 ;
        else if (rem <= 10 )Di = -c ;
        else 
        Di = (rem-10) * (rem-10); 
        ret = min (ret , Di + solve1(i+1 , lec + 1 ));
        i++;
    }
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0; 
    while (cin >> n && n )
    {
        if (T)cout <<"\n"; 
        T++;
        cin >> l >> c ;
        for (int i =0 ; i < n ;i++)
            cin >> a[i];
        memset(dp , -1 ,sizeof dp);
        memset(dp1 , -1 ,sizeof dp1 ); 
        Lec = solve();
        D = solve1();
        cout << "Case " << T <<":\n"; 
        cout <<"Minimum number of lectures: " << Lec <<"\n"; 
        cout <<"Total dissatisfaction index: " << D <<"\n"; 
    }

}