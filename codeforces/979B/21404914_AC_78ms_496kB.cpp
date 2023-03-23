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
string x , y , z ;
int need (string x )
{
    map <char,int> mp ;
    for (int i =0 ; i < SZ(x) ;i++)mp[ x[i] ]++;
    int mx = 0 ;
    for (auto m : mp )
        mx = max (mx , m.s );
    return SZ(x) - mx ;
}
int beaty (string x )
{
    map <char,int> mp ;
    for (int i =0 ; i < SZ(x) ;i++)mp[ x[i] ]++;
    int mx = 0 ;
    for (auto m : mp)mx = max (mx , m.s );
    return mx ;
}
int cal (int a , int A)
{
    int ret = A ;
    if (n >= a )
    {
       ret = SZ(x) ;
       if (n - a == 1 && n == 1 )ret--;
    }else
    ret += n ;
    return ret ;
}
int main()
{

cin >> n ;
cin >> x >> y >> z ;
int a = need(x);
int b = need(y);
int c = need(z);
int A = beaty(x);
int B = beaty(y);
int C = beaty(z);
//cout << a <<" " << b <<" " << c <<"\n";
//cout << A <<" " << B <<" " << C <<"\n";
//cout << n-a << " " << n-b << " " << n-c <<"\n";
A = cal(a , A );
B = cal(b , B );
C = cal(c , C );
int mx = max ( max (A , B) , C );
int cnt =0 ;
if (A == mx )cnt++;
if (B == mx )cnt++;
if (C == mx )cnt++;
//cout << A <<" " << B << " " << C <<"\n";
if (cnt >= 2 )
{
    printf ("Draw\n");
}else
{
    if (mx == A )
    {
        printf ("Kuro\n");
    }else if (mx == B )
    {
        printf ("Shiro\n");
    }else
    {
        printf ("Katie\n");
    }
}
}
