// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf("%d" , &n )
void fo (){fflush(stdout);}
using namespace std;
ll fact (int x ){return (x <= 1 ? 1 : 1LL * x * fact (x-1));}
string a [50], b[50] ;
int n , m ;
bool ok (int x , int y )
{
  for (int i = x , ro = 0 ; i - x < m ;ro++ , i++)
  {
    for (int j = y , col = 0 ; j - y < m ;col++ , j++)
    {
      if (a[i][j] != b[ro][col])return false ;
    }
  }
  return  true ;
}
int main ()
{
  cin >> n >> m ;
  for (int i =0 ; i < n ;i++)cin >> a[i];
  for (int i =0 ; i < m ;i++)cin >> b[i];

  for (int i =0 ; i + m <=  n ;i++)
  {
    for (int j =0 ; j + m <=  n ;j++)
    {
      if (ok(i , j ))
      {
        cout <<"Yes\n";
        return 0 ;
      }
    }
  }
  cout <<"No\n";
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}