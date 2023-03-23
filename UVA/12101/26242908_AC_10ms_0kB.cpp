// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int P[10009];
bool prime(int num)
{
  if (~P[num])return P[num];
  for (int i = 2; i <= num/i; i++)
  {
    if (num%i == 0)
    {
      return P[num] = 0;
    }
  }
  return P[num] = (num > 1);
}
int main()
{
  memset(P, -1, sizeof P);
  int t;
  cin >> t;
  while (t--)
  {
    string s, x;
    cin >> s >> x;
    queue<pair<string,int>> q;
    q.push({s, 0});
    set<int> seen;
    int ans = -1;
    while(!q.empty())
    {
      auto cur = q.front();
      q.pop();
      if (cur.f == x)
      {
        ans = cur.s;
        break;
      }
      for (int i =0; i < 4; i++)
      {
        string tm;
        for (char d = '0' + !i; d <= '9'; d++)
        {
          tm = cur.f;
          tm[i] = d;
          int number = atoi(tm.c_str());
          if (prime(number) && seen.find(number) == seen.end())
          {
            seen.insert(number);
            q.push({tm, cur.s + 1});
          }
        }
      }
    }
    cout << ans <<"\n"; 
  }
}
