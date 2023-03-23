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
int mn (char a , char b )
{
  // LOL
  int cur = abs(a - b ) ;
  cur = min (cur , ('Z' - a) + 1 + ( b - 'A') );
  cur = min (cur , (a - 'A') + 1 + ('Z' - b));
  return cur ;
}
int n ;
int k ;
pair<int,pair<int,int>> cp[1000];
pair<int,int> tab[1000];
bool cmp (pair<int,pair<int,int>> &a , pair<int,pair<int,int>>&b )
{
  return a.s.f > b.s.f ;
}
int main ()
{
  scanf ("%d", &n );
  for (int i =0 ; i < n ;i++)
  {
    scanf ("%d%d" , &cp[i].f , &cp[i].s.f  );
    cp[i].s.s = i+1 ;
  }
  sort(cp , cp + n , cmp );
  scanf ("%d" ,&k );

  for (int i =0 ;i < k ;i++)
  {
    scanf ("%d" , &tab[i].f  );
    tab[i].s = i+1 ;
  }
  sort(tab , tab + k );
  vector < pair<int,int> > ans ;
  int ac= 0 ;
  ll money = 0 ;

  for (int i =0 ; i < n ;i++)
  {
    for (int j = 0 ; j < k ;j++ )
    {
      if (tab[j].f >= cp[i].f && tab[j].f != -4 )
      {
        money += cp[i].s.f ;
        ac++;
        ans.pb({cp[i].s.s , tab[j].s });
        tab[j].f = -4 ;
        break;
      }
    }
  }
  printf ("%d %lld\n" , ac , money );
  for (int i =0 ;i < ac ;i++)
  printf ("%d %d\n" , ans[i].f , ans[i].s );
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
