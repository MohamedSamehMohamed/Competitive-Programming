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
int ans;
void solve(int a, int b)
{
  int cur = 0;
  for (int i = 0; i < SZ(x); i++)
  {
    if (x[i] - '0' == a)
    {
      cur++;
      swap(a, b);
    }
  }
  if (cur % 2 && a != b)cur--;
  ans = max(ans, cur);
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    ans = 0;
    cin >> x;
    for (int i = 0; i <= 10; i++)
      for (int j = 0; j <= 10; j++)
        solve(i, j);
    cout << SZ(x) - ans << "\n";
  }
}
