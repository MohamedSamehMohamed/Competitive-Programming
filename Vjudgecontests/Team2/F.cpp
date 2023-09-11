// Author : Mohamed Sameh
// created in: 11:02 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, q;
long long prefix[N];
int fun[N];
void test(){
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++){
    scanf("%d", fun + i);
  }
  prefix[0] = 0;
  for (int i = 1; i <= n; i++){
    prefix[i] = prefix[i-1] + fun[i];
  }
  vector<long long> death;
  for (int i = 1; i <= n; i++){
    long long toDie = 1LL * fun[i]
            + min(prefix[i-1], prefix[n]-prefix[i]);
    death.push_back(toDie);
  }
  sort(death.begin(), death.end());
  while (q--){
    long long s;
    scanf("%lld", &s);
    int l = 0, r = death.size() - 1, m, ans = 0;
    while (l <= r){
      m = (l+r) >> 1;
      if (death[m] <= s)
        ans = m+1, l = m + 1;
      else
        r = m - 1;
    }
    printf("%d\n", n - ans);
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}