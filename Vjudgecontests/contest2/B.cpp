// Author : Mohamed Sameh
// created in: 8:38 PM
#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  vector<int> a(n), b(n), ord(n);
  iota(ord.begin(), ord.end(), 0);
  for (int i = 0; i < n; i++){
    scanf("%d%d", &a[i], &b[i]);
  }
  sort(ord.begin(), ord.end(), [&](int i, int j){
    if (a[i] != a[j])
      return a[i] > a[j];
    return 2LL * a[i] + b[i] > 2LL * a[j] + b[j];
  });
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum -= a[i];
  for (int i = 0; i < n; i++){
    sum += 2LL * a[ord[i]] + b[ord[i]];
    if (sum > 0){
      printf("%d\n", i + 1);
      return;
    }
  }
}
int main()
{
  test();
}