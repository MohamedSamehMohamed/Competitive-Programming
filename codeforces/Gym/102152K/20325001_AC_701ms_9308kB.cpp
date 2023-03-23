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
int t ;
int n ;
int a[100000];
int main ()
{
  scanf ("%d" , &t );
  while (t--)
  {
    set <int> ans , cur ;
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)scanf ("%d" ,a +i );
    cur.insert(0);
    for (int i = 0 ; i < n ;i++)
    {
      set <int>tem ;
      for (auto s : cur )
      {
        tem.insert(s | a[i]);
      }
      tem.insert(a[i]);
      cur = tem ;
      for (auto s : cur )
      ans.insert(s);
    }

    cout <<SZ(ans) << "\n";
  }

//  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
