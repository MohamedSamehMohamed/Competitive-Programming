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
const int N = 101;
int n, m;
set<string> Users;
string ans[N][2];
set<string> forbid[N];
map<string,int> mp;
bool ok (char c)
{
  if (c >= 'a' && c <= 'z')return 1;
  if (c >= 'A' && c <= 'Z')return 1;
  if (c >= '0' && c <= '9')return 1;
  return 0;
}
void extract(int idx, string x)
{
  string tm = "";
  x += '!';
  for (int i = 0; i < SZ(x); i++)
  {
    if ( !ok(x[i]) )
    {
      // check
      if (Users.find(tm) != Users.end())forbid[idx].insert(tm);
      tm = "";continue;
    }
    tm += x[i];
  }
}
int dp[N][N];
int solve(int idx = 0, int lst = 100)
{
  if (idx == m)return 1;
  int &ret = dp[idx][lst];
  if (~ret)return ret;
  ret =0 ;
  if (ans[idx][0][0] != '?')
  {
    if (mp[ ans[idx][0] ] == lst)return ret = 0;
    return ret = solve(idx+1, mp[ ans[idx][0] ]);
  }
  for (auto i: mp)
  {
    if (i.s == lst)continue;
    if (forbid[idx].find(i.f) != forbid[idx].end())continue;
    ret = solve(idx+1, i.s);
    if (ret)break;
  }
  return ret;
}
void build(int idx = 0, int lst = 100)
{
  if (idx == m)return ;
  int ret = dp[idx][lst];
  if (ans[idx][0][0] != '?')
  {
    if (mp[ ans[idx][0] ] == lst)return;
    build(idx+1, mp[ ans[idx][0] ]);
    return;
  }
  for (auto i: mp)
  {
    if (i.s == lst)continue;
    if (forbid[idx].find(i.f) != forbid[idx].end())continue;
    int cur = solve(idx+1, i.s);
    if (cur == ret)
    {
      ans[idx][0] = i.f;
      build(idx+1, i.s);
      break;
    }
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    memset(dp, -1, sizeof dp);
    Users.clear();
    mp.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      string x;
      cin >> x;
      
      Users.insert(x);
      mp[x] = i;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      forbid[i].clear();
      string S = "", user = "";
      while(SZ(S) == 0)getline(cin , S);
      string msg = "";
      int j;
      for (j = 0; j < SZ(S) && S[j] != ':'; j++)user+=S[j];
      j++;
      while (j < SZ(S))
      {
        msg+=S[j];
        j++;
      }
      ans[i][0] = user;
      ans[i][1] = msg;
      if (user[0] != '?')continue;
      extract(i, msg);
    }
    if (solve())
    {
      build();
      for (int i = 0; i < m; i++)
      {
        cout << ans[i][0] <<":" << ans[i][1] <<"\n";
      }
    }else
    {
      cout <<"Impossible\n";
    }
  }
}
