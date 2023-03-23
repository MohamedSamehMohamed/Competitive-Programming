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
int main ()
{
  int n ;
  scanf ("%d" , &n );
  string tem , fin = "";
  for (int i =0 ; i < n ;i++)
  {
    cin >> tem ;
    fin += tem ;
    if (i + 1 != n )fin += ' ';
  }
  int m ;
  scanf ("%d" , &m );
  stack <char> sk ;
  bool state = 0 ;
  for (int i =0 ; i < m ; i++)
  {
    string cur ;
    cin >> cur ;
    if (cur == "CapsLock")
    {
      state = !state ;
    }else if (cur ==  "Backspace" )
    {
      if (!sk.empty())sk.pop();
    }else if (cur == "Space")
    {
      sk.push(' ');
    }else
    {
      if (state)sk.push(cur[0] - 32 );
      else
      sk.push(cur[0]);
    }
  }
  bool ok = 1 ;
  string ans = "";
  while (!sk.empty())
  {
    ans += sk.top();
    sk.pop();
  }
  for (int i =0 , j = SZ(ans) -1 ; i < j ; i++ , j--)
  {
    swap (ans[i] , ans[j]);
  }
  if (ans == fin )
  cout << "Correct\n";
  else
  cout <<"Incorrect\n";
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
