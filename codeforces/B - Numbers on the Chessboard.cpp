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
void print(int n)
{
  int fi = (n * n + 1)/2;
  int a = 1;
  int b = fi+1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if ((i+j)&1)
      {
        cout << b <<" ";
        b++;
      }else
      {
        cout << a <<" ";
        a++;
      }
    }
    cout <<"\n";
  }
}
int main()
{
  int n, q;
  cin >> n >> q;
  ll fi = (1LL * n * n+1)/2 ;
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    ll cur =  1LL * (x-1) * n + y - 1;
    int dumy = ((x+y)%2);
    ll rem = cur - ((cur+dumy)/2);
    cur = (cur + dumy)/2;
    if ((x+y)&1)
      printf("%lld\n", fi+rem+1);
    else
      printf("%lld\n", cur + 1);
 
 
 
 
  }
}
