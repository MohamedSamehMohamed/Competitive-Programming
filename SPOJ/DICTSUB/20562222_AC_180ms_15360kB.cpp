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
int sum (string x )
{
  int ret =0 ;
  for (int i = SZ(x) -1 , k =1 ; i >= 0 ; i--, k*=10)
  {
    ret += ((int)x[i] - '0' )*k ;
  }
  return ret ;
}
int main ()
{
  int t ;
  cin >> t ;
  while (t--)
  {
    int n ;
    string x ;
    cin >> n >> x ;
    vector <int> adj[26];
    for (int i =0 ; i < SZ(x) ; i++)
    adj[x[i] - 'A'].pb(i);

    while (n--)
    {
      string y ;
      cin >> y ;
      string tem  = "";
      int last = -1 ;
      bool done = 1;
      for (int i =0 ; i < SZ(y) ;i++)
      {
        if (y[i] >= 'A' && y[i] <= 'Z')
        {
          int oc = sum (tem);
          //cout << oc <<" " << tem <<"\n";
          //cout << "last " << last <<"\n";
          tem = "";
          // Amr Hassn Will Say . . .
          int l = 0 , r = SZ(adj[y[i] - 'A']) - 1 , m , a1 = -1  ;
          while (l <= r )
          {
            m = (l+r)>>1;
            if (adj[y[i]- 'A'] [m] > last )
            {
              a1 = m ;
              r = m-1;
            }else
            l = m+1;
          }
          if (a1 == -1 || a1 + oc - 1 >= SZ(adj[y[i] - 'A']))
          {
            done = 0 ;
            break;
          }
          last = adj[y[i]-'A'][a1+oc-1] ;
        }else
        tem += y[i];
      }
      if (!done)
      {
        cout <<"NO\n";
      }else
      cout <<"YES\n";
    }
  }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
