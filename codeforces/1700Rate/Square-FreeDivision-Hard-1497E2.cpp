// Author : Mohamed Sameh
// created in: 5:11 PM
#include <bits/stdc++.h>
using std::vector;
const int N = 1e7 + 9, M = 2e5 + 9;
int n, k;
int sieve[N], a[M];
int factors[N];
int vis[N], vid;
void Siev()
{
  vector<int> primes;
  sieve[0] = sieve[1] = 1;
  factors[0] = factors[1] = 1;
  for(int i = 2; i < N; i++)
  {
    factors[i] = 1;
    if (sieve[i] == 0)
    {
      sieve[i] = i;
      primes.push_back(i);
    }
    for(int &p: primes)
    {
      if (i * p >= N)
        break;
      sieve[i * p] = p;
    }
  }
  for(int i = 2; i < N; i++)
  {
    int cur = i;
    int c = 0;
    int d = sieve[cur];
    while (cur != 1 && cur % d == 0)
    {
      cur /= d;
      c ^= 1;
    }
    if (c)
      factors[i]*=d;
    factors[i] *= factors[cur];
  }
}
int left[M][21];
int dp[M][21];
void test(){
  scanf("%d%d", &n, &k);
  vid += 21;
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    a[i] = factors[a[i]];
  }
  for (int j = 0; j <= k; j++){
    vid+=k+1;
    int l = 0, r = 0;
    int rm = j;
    left[r][j] = r;
    while (r < n){
      while (r < n && (vis[a[r]] < vid || rm > 0) ){
        if (vis[a[r]] >= vid){
          vis[a[r]]++;
          rm--;
        }
        else {
          vis[a[r]] = vid;
        }
        left[r][j] = l;
        r++;
      }
      vis[a[l]]--;
      if (vis[a[l]] >= vid)
        rm++;
      l++;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      dp[i][j] = i? n: 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= k; j++){
      if (j > 0) dp[i][j] = dp[i][j-1];
      for (int lst = 0; lst <= j; lst++){
        dp[i][j] = std::min(dp[i][j], dp[left[i-1][lst]][j - lst] + 1);
      }
    }
  }
  int ans = n;
  for (int i = 0; i <= k; i++)
    ans = std::min(ans, dp[n][i]);
  printf("%d\n", ans);

}
int main()
{
  Siev();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
 * 0 0 0 1 2
 *
 */