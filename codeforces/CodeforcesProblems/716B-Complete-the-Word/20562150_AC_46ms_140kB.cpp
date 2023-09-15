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
string x ;
int frq[26];
bool check ()
{
  for (int i =0 ; i < 26 ;i++)
  {
    if (frq[i] > 1 )return false ;
  }
  return true ;
}
int main ()
{
  cin >> x ;
  if (SZ(x) < 26 )
  {
    cout <<"-1\n";
    return 0 ;
  }
  int rep = 0 ;
  int dif = 0 ;
  for (int i =0 ; i < 25 ; i++)
  {
    if (x[i] == '?')
    {
      rep++;
      continue ;
    }
    if (++frq[x[i] - 'A'] == 1 )dif++;
  }
  bool ok = 0 ;
  for (int i =0 , j = 25 ; j < SZ(x) ;i++,j++)
  {
    if (x[j] == '?')
    {
      rep++;
    }else
    {
      if (++frq[x[j] - 'A'] == 1)dif++;
    }
    if (dif + rep == 26 && check ())
    {
      ok = 1;
      for (int k = i ; k <= j ; k++)
      {
        if (x[k] != '?')continue ;
        for (int f = 0 ;f < 26 ; f++)
        {
          if (frq[f] == 0 )
          {
            x[k] = char (f + 'A');
            frq[f] = 1;
            break;
          }
        }
      }
      break;
    }
    if (x[i] == '?')
    {
      rep--;
      continue ;
    }
    if (--frq[x[i] - 'A'] == 0 )dif--;
  }
  if (ok)
  {
    for (int i =0 ;i < SZ(x) ;i++)
    {
      if (x[i] != '?')cout << x[i];
      else
      cout <<'A';
    }
  }else
  cout <<"-1\n";

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
