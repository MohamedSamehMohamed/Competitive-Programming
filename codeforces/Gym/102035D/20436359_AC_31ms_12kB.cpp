// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}
using namespace std;

int n , a , b , s ;
int arr[100];
int main ()
{
  scanf ("%d%d%d%d" , &n ,&a , &b ,&s );
  n--;
  s-=a;
  if (a != b )
  {
    n--;
    s-=b;
  }
  if (n < 0 || s < 0 )
  {
    printf ("NO\n");
    return 0 ;
  }
  int cur =a * n  ;
  for (int i =0 ; i < n ;i++)
  {
    arr[i] = a ;
  }
  while (cur < s )
  {
    bool ch =0 ;
    for (int i =0 ; cur < s && i < n ;i++)
    {
      while ( cur < s && arr[i] + 1 <= b )
      {
        cur++;
        ch = 1 ;
        arr[i]++;
      }
    }
    if (!ch)break;
  }
  if (cur == s )
  {
    printf ("YES\n");
  }else
    printf ("NO\n");


  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
