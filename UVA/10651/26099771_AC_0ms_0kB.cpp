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
string x;
const int N = 12;
int dp[(1<<N)];
bool Is_set(int msk, int idx){return (msk & (1<<idx)) != 0;}
void Set(int& msk, int idx){msk |= (1<<idx);}
void clear(int& msk, int idx){msk &= ~(1<<idx);}
int count(int msk)
{
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if ((msk&(1<<i)))cnt++;
  }
  return cnt;
}
int solve(int msk)
{
  if (!msk)return 0;
  int &ret = dp[msk];
  if (~ret)return ret;
  ret = 0;
  for (int i = 0; i < N; i++)ret+=Is_set(msk, i);
  for (int i = 0; i + 2< N; i++)
  {
    if (Is_set(msk, i) && Is_set(msk, i+1) && !Is_set(msk, i+2))
    {
      int nmsk = msk;
      clear(nmsk, i);
      clear(nmsk, i+1);
      Set(nmsk, i+2);
      ret = min(ret, solve(nmsk));
    }
    if (!Is_set(msk, i) && Is_set(msk, i+1) && Is_set(msk, i+2))
    {
      int nmsk = msk;
      Set(nmsk, i);
      clear(nmsk, i+1);
      clear(nmsk, i+2);
      ret = min(ret, solve(nmsk));
    }
  }
  return ret;
}
void test()
{
  memset(dp, -1, sizeof dp);
  cin >> x;
  int msk = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++)
    if (x[i] == 'o')msk|=(1<<i),cnt++;
  cout << solve(msk) <<"\n";
}
int main()
{
  int t; cin >> t;
  while (t--)test();
}
