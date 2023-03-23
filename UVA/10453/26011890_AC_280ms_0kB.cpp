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
const int N = 1009;
int dp[N][N];
int n;
string x;
int solve(int l = 0, int r = n-1)
{
  if (l > r)return 0;
  int &ret = dp[l][r];
  if (~ret)return ret;
  ret = 1e9;
  if (x[l] == x[r])ret = solve(l+1, r-1);
  return ret = min(ret, 1 + min(solve(l+1, r),solve(l, r-1)));
}
stack<char> R;
queue<char> L;
void build (int l = 0, int r = n-1)
{
  if (l > r)return;
  int ret = dp[l][r];
  int p1 = (x[l] == x[r] ? solve(l+1, r-1): 1e9);
  int p2 = 1 + solve(l+1, r);
  int p3 = 1 + solve(l, r-1);
  if (p1 == ret)
  {
    L.push(x[l]);
    if (l != r)
    R.push(x[r]);
    build(l+1, r-1);
  }else if (p2 == ret)
  {
    //cout << "insert " << x[l] <<" right\n";
    R.push(x[l]);
    L.push(x[l]);
    build(l+1, r);
  }else
  {
    L.push(x[r]);
    R.push(x[r]);
    //cout <<"insert " <<  x[r] <<" left\n";
    build(l, r-1);
  }
}
int main()
{
  while (cin >> x)
  {
    n = SZ(x);
    memset(dp, -1, sizeof dp);
    cout << solve() <<" ";
    build();
    while (!L.empty())
    {
      cout << L.front();
      L.pop();
    }
    while(!R.empty())
    {
      cout << R.top();
      R.pop();
    }
    cout <<"\n";
  }
}
