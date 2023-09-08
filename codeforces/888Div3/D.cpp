// Author : Mohamed Sameh
// created in: 1:19 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n;
  scanf("%d", &n);
  vector<long long> a(n-1);
  for (int i = 0; i < n-1; i++)
    scanf("%lld", &a[i]);
  long long sum = (1LL * n * (n+1)) >> 1LL;
  bool inRange = true;
  for (int i = 0; i < n-1; i++){
    inRange &= (a[i] >= 1 && a[i] <= sum);
  }
  if (!inRange){
    printf("No\n");
    return;
  }
  vector<bool> seen(n+1, 0);
  bool ok = 1;
  if (sum != a[n-2]){
    a.push_back(sum);
    for (int i = 0; i < n; i++){
      long long cur = a[i] - (i? a[i-1]: 0);
      if (cur >= 1 && cur <= n)
      {
        if (seen[cur]) ok = 0;
        seen[cur] = 1;
      }else
        ok = 0;
    }
  }else{
    /*
     *
     */
    // 1 2 3  4  5
    // 1 3 6 10 15
    // 2 3 4 1  5
    // 2 5 9 10 15
    long long dif = -1;
    for (int i = n-2; i >= 0; i--){
      long long cur = a[i] - (i? a[i-1]: 0);
      if (cur >= 1 && cur <= n && !seen[cur]){
        seen[cur] = 1;
      }else{
        if (dif == -1)
          dif = cur;
        else
          ok = 0;
      }
    }
    ok &= (dif != -1);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
      if (!seen[i]){
        dif -= i;
        cnt++;
      }
    }
    ok &= (cnt == 2 && dif == 0);
  }
  printf("%s\n", (ok? "Yes": "No"));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}