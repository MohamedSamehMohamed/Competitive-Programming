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
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;
int n ;
int a[100000];
int pre[100001];
int main ()
{
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++)scanf ("%d" , a+i );
  for (int i =1 ; i <= n ;i++)
  {
    pre[i] = pre[i-1] + a[i-1];
  }
  int q ;
  scanf ("%d" , &q );
  while (q--)
  {
    int l , r ;
    scanf ("%d%d" , &l ,&r );
    l--;
    printf ("%d\n" , (pre[r] - pre[l])/10 );
  }
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}