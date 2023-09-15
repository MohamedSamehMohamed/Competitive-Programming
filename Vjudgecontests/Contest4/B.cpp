// Author : Mohamed Sameh
// created in: 9:36 PM
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
long long fast(int bb, int p){
  if (p == 0) return 1;
  if (p == 1) return bb;
  if (p % 2) return fast(bb, p-1) * bb;
  long long cur = fast(bb, p / 2);
  return cur * cur;
}
int sumDi(long long num){
  return num == 0? 0: num % 10+ sumDi(num / 10);
}
void test(){
  // x = b * s(x)^a + c
  int up = 1e9;
  scanf("%d%d%d", &a, &b, &c);
  vector<int> ans;
  for (int sum = 1; sum <= 100; sum++){
    long long sxa = fast(sum, a);
    long long x = 1LL * b * sxa + c;
    if (x > 0 && x < up && sumDi(x) == sum){
      ans.push_back(x);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i: ans) printf("%d ", i);
  printf("\n");
}
int main()
{
  test();
}