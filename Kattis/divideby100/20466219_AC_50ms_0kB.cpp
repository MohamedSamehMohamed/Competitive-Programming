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
int main ()
{
  string x , y ;
  cin >> x >> y ;
  int rm = SZ(y)-1;
  int i = SZ(x) - 1;
  stack <char> out ;
  for ( ; i >= 0 && rm ; rm--,i--)
  out.push(x[i]);

  if (rm == 0 )out.push('.');
  else
  {
    while (rm)
    {
      out.push('0');
      rm--;
    }
    out.push('.');
  }
  while (i >=0 )
  {
    out.push(x[i]);i--;
  }
  string ans = "";
  while (!out.empty())
  {
    if (SZ(ans) == 0 && out.top() == '.')ans+='0';
    ans += out.top();
    out.pop();
  }
  int last = SZ(ans) ;
  for (int i =SZ(ans)-1 ; i >-1  ;i--)
  {
    if (ans[i] != '0')
    {
      last = i+1 ;
      break;
    }
  }
  for (int i =0 ; i < last ;i++)
  {
    if (i + 1 == last && ans[i] == '.')break;
    cout << ans[i] ;
  }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;

}
