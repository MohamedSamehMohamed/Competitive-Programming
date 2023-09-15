// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e7 + 9;
int frq[N];
int main()
{
  int p;
  long long n;
  cin >> p >> n;
  int ans = 1;
  int jump = 1;
  int cur = 0;
  long long rep = min(n, 1LL * 5 * p);
  frq[cur] = 1;
  while(rep--)
  {
    cur = (1LL*cur + jump) % p;
    if (++frq[cur] == 1)ans++;
    jump++;
  }
  printf("%d\n", ans);
}
