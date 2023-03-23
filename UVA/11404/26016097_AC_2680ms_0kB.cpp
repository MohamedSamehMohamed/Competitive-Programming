// Author : Mohamed Sameh
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
const int N = 1e3+1;
pair<int,string> dp[N][N];
int n;
string x;
char c = ' ';
string low (string y)
{
  for (int i = 0; i < SZ(y); i++)
    if (y[i] < 'a')y[i] += 32;
  return y;
}
pair<int,string> max (pair<int,string> a, pair<int,string> b)
{
  if (a.f != b.f)
  {
    if (a.f > b.f)return a;
    return b ;
  }
  for (int i = 0; i < SZ(a.s); i++)
  {
    char X, Y;
    X = a.s[i];
    Y = b.s[i];
    if (X < 'a')X+=32;
    if (Y < 'a')Y+=32;
    if (X < Y)
    {
      return a;
    }
    if (X > Y)
    {
      return b;
    }
  }
  return b ;
}
pair<int,string> solve(int l = 0, int r = n-1)
{
  pair<int,string> tm;
  tm.f = 0;
  tm.s = c;
  if (l > r)return tm;
  pair<int,string> ret = dp[l][r];
  if (~ret.f)return ret;
  ret = max(solve(l+1, r),solve(l, r-1));
  if (x[l] == x[r]){
  tm = solve(l+1, r-1);
  tm.f++;
  char tk = x[l];
  if (l != r){tk-=32,tm.f++;}
  tm.s=tk + tm.s;
  ret = max(ret, tm);
  }
  return dp[l][r] = ret;
}
int main()
{
  //freopen("T.txt" ,"r", stdin);
  while (cin >> x)
  {
    n = SZ(x);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dp[i][j].f = -1;
    string ans = solve().s;
    queue<char> q;
    stack<char> sk;
    for (int i = 0; i < SZ(ans); i++)
    {
      if (ans[i] == ' ')continue;
      if (ans[i] >= 'a')
      {
        q.push(ans[i]);
      }else
      {
        ans[i]+=32;
        q.push(ans[i]);
        sk.push(ans[i]);
      }
    }
    while (!q.empty())
    {
      cout << q.front();
      q.pop();
    }
    while (!sk.empty())
    {
      cout << sk.top();
      sk.pop();
    }
    cout <<"\n";
  }
}
