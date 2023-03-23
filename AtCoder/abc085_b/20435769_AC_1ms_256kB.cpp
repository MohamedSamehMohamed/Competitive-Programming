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

int a[100];
int main ()
{

  int n ;
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++)scanf ("%d" ,a+i ) ;
  sort(a,a+n);
  int pr = n-1 ;
  int ans = 1;
  for (int i = n-2 ; i >=0 ;i--)
  {
    if (a[i] < a[pr])
    {
      pr = i ;
      ans++;
    }
  }
  printf ("%d\n" , ans );

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
