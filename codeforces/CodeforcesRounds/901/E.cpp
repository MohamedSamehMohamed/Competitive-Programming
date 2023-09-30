// Author : Mohamed Sameh
// created in: 7:12 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  long long a, b, c, d, m;
  scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &m);
  queue<vector<long long>> q;
  map<vector<long long>, bool> seen;
  map<long long, int> seen2;
  auto check = [&](vector<long long>& A){
    long long xo = A[0] & A[1];
    if (seen.count(A) == 0 && seen2.count(xo) < 2){
      seen[A] = 1;
      seen2[xo]++;
      return 1;
    }
    return 0;
  };
  q.push({a, b});
  int cnt = 0;
  int xo = a ^ b;
  int lim = 0;
  for (int i = 0; i < 30; i++)
    lim += (xo&(1<<i)) != 0;
  if (lim == 0) lim = 30;
  while (!q.empty()){
    int sz = q.size();
    if (cnt > lim) break;
    while (sz--) {
      auto cur = q.front();
      q.pop();
      if (cur[0] == c && cur[1] == d){
        printf("%d\n", cnt);
        return;
      }
      vector<long long> temp = cur;
      temp[0] &= temp[1];
      if (check(temp)){
        q.push(temp);
      }
      temp = cur;
      temp[0] |= temp[1];
      if (check(temp)){
        q.push(temp);
      }
      temp = cur;
      temp[1] ^= temp[0];
      if (check(temp)){
        q.push(temp);
      }
      temp = cur;
      temp[1] ^= m;
      if (check(temp)){
        q.push(temp);
      }
    }
    cnt++;
  }
  printf("-1\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}