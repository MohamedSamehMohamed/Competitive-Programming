// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
string x;
string str = "abacaba";
int n;
bool exist(int i)
{
  string cur = "";
  while(SZ(cur) < SZ(str))
  {
    cur += x[i];
    i++;
  }
  return cur == str;
}
int count()
{
  int occ = 0;
  for (int i = 0; i + SZ(str) <= n; i++)
  {
    occ += exist(i);
  }
  return occ;
}
void ZZ()
{
  for (int i = 0; i < SZ(x); i++)if (x[i] == '?')x[i] = 'z';
}
bool ok (int id)
{
  string tm = x;
  int k =0 ;
  while(k < SZ(str))
  {
    x[id] = str[k];
    id++;
    k++;
  }
  ZZ(); 
  int c = count();
  if (c == 1)
  {
    return 1;
  }
  x = tm;
  return 0;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> x;
    int cur = count();
    if (cur > 1)
    {
      cout <<"No\n";
      continue;
    }
    if (cur == 1)
    {
      ZZ();
      cur  = count();
      if (cur == 1)
        cout <<"Yes\n" << x <<"\n";
      else
        cout <<"No\n";
      continue;
    }
    bool can = 0;
    for (int i = 0; i + SZ(str) <= n; i++)
    {
      int j = i;
      int k = 0;
      while(k < SZ(str))
      {
        if (x[j] == '?' || str[k] == x[j])
        {
          k++;
          j++;
        }else
        break;
      }
      if (k == SZ(str) && ok(i))
      {
        can = 1;
        break;
      }
    }
    if(can)cout<<"YES\n" << x <<"\n";
    else
    cout <<"No\n";
  }
 
}
