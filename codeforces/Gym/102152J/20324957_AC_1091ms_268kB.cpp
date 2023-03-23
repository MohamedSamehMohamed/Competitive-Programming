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
int n , m ;
int a[1000];
int id =1 ;
int main ()
{
  scanf ("%d" , &t );
  while (t--)
  {

    scanf ("%d%d" , &n , &m );
    map <int,int> mp ;
    for (int j =0 ; j < m ;j++)
    {
      int val ;
      scanf ("%d" , &val );
      mp[val]++;
    }
    int ans =0;
    for (int i =1 ; i < n ;i++)
    {
      map <int ,int >tem ;
      for (int j = 0 ; j < m ;j++)
      {
        int val ;
        scanf ("%d" , &val );
        tem[val]++;
        if (mp[val])
        {
          ans++;
          mp[val]--;
        }
      }
      mp = tem ;
    }
    printf ("%d\n" ,ans );
  }

//  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
