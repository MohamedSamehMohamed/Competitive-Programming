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
const int N = 2e5+9;
int n, k;
string str, X = "RGB";
int pre[N];
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> k >> str;
    int ans = n;
    for (int j = 0; j < 3; j++)
    {
      int cur = 0;
      for (int i = 0; i < n; i++)
      {
        pre[i] = (str[i] != X[(i + j)%3]);
        cur += pre[i];
        if (i - k >= 0)cur -= pre[i-k];
        if (i >= k-1)ans = min(ans, cur);
      }
    }
    cout << ans << '\n';
  }
}
