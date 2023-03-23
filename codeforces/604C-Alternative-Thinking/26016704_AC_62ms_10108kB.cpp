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
const int N =1e5+1, MN = -1e9;
int dp[N][3][3], n;
bool a[N];
string x;
/*
0-> not used
1-> isused
2-> closed
*/
int solve(int i = 0, int lst = 2, int state = 0)
{
  if (i == n)
  {
    if (!state) return MN;
    return 0;
  }
  int &ret = dp[i][lst][state];
  if (~ret) return ret;
  ret = solve(i+1, lst, state);
  if (lst == 2)
  {
    ret = max(ret, 1 + max(solve(i+1, a[i], 0), solve(i+1, a[i]^1, 1)));
    return ret;
  }
  if (state == 0)
  {
    if (a[i] != lst)
      ret = max(ret, 1 + solve(i+1, a[i], 0));
    else
      ret = max(ret, 1 + max(solve(i+1, a[i]^1, 2), solve(i+1, a[i]^1, 1)));
  }else if (state == 1)
  {
    ret = max(ret, max(solve(i+1, lst, 1),solve(i, lst, 2)));
    if (a[i] == lst)
      ret = max(ret, 1 + max(solve(i+1, a[i]^1, 2),solve(i+1, a[i]^1, 1)));
  }else
  {
    if (a[i] != lst )ret = max(ret, 1 + solve(i+1, a[i] , 2));
    ret = max(ret, solve(i+1, lst, 2));
  }
  return ret;
}
void build (int i = 0, int lst = 2, int state = 0)
{
  cout <<"\n{ " << i + 1<<" " << lst <<" " << state <<" }\n";
  if (i == n)
  {
    return ;
  }
  int ret = dp[i][lst][state];
  int skip = solve(i+1, lst, state);
  if (ret == skip)
  {
    build(i+1, lst , state);
    return;
  }
  if (lst == 2)
  {
    int p1 = 1 + solve(i+1, a[i], 0);
    int p2 = 1 + solve(i+1, a[i]^1, 1);
    if (ret == p1 )
    {
      cout << a[i] ;
      build(i+1, a[i], 0);
      return;
    }else if (ret == p2)
    {
      cout << (a[i]^1);
      build(i+1, a[i]^1, 1);
      return;
    }
  }
  if (state == 0)
  {
    int p1 = 1 + solve(i+1, a[i], 0);
    int p2 = 1 + solve(i+1, a[i]^1, 2);
    int p3 = solve(i+1, a[i]^1, 1);
    if (a[i] != lst)
    {
      if (ret == p1)
      {
        cout << a[i];
        build(i+1, a[i], 0);
        return ;
      }
    }else
    {
      if (ret == p2 )
      {
        cout << (a[i]^1);
        build(i+1, a[i]^1, 2);
        return;
      }else if (ret == p3)
      {
        build(i+1, a[i]^1, 1);
        return;
      }
    }
  }else if (state == 1)
  {
    int p1 = solve(i+1, lst, 1);
    int p2 = solve(i, lst, 2);
    if (ret == p1)
    {
      build(i+1, lst, 1);
      return;
    }else if (ret == p2)
    {
      build(i, lst, 2);
      return;
    }
    if (a[i] == lst)
    {
     int p1 = 1 + solve(i+1, a[i]^1, 2);
     int p2 = 1 + solve(i+1, a[i]^1, 1);
     if (p1 == ret)
     {
       cout << (a[i]^1) ;
       build(i+1, a[i]^1, 2);
       return ;
     }else if (p2 == ret)
     {
       cout << (a[i]^1);
       build(i+1, a[i]^1, 1);
       return ;
     }
   }
  }else
  {

    if (a[i] != lst ){
      int p1 = 1 + solve(i+1, a[i] , 2);
      if (p1 == ret)
      {
        cout << a[i];
        build(i+1, a[i], 2);
        return;
      }
    }
    int p1 = solve(i+1, lst, 2);
    if (p1 == ret)
    {
      build(i+1, lst, 2);
    }
  }
}
int main()
{
  cin >> n >> x;
  for (int i = 0; i < n; i++)a[i] = (x[i] == '0' ? 0 : 1);
  memset(dp, -1, sizeof dp);
  cout << solve() <<"\n";
//  build();
}
