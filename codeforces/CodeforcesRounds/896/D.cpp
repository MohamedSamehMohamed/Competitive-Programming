// Author : Mohamed Sameh
// created in: 4:55 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  long long sum = 0;
  for (int i = 0; i <n ; i++)
    sum += a[i];
  if (sum % n){
    printf("No\n");
    return;
  }
  sort(a, a+n);
  sum /= n;
  map<int, int> mp;
  bool ok = 1;
  for (int p = 0; p < n; p++){
    int p2 = p + 1;
    while (p2 < n && a[p] == a[p2])
      p2++;
    int len = p2 - p;
    bool exist = 0;
    for (int i = 0; i <= 30; i++){
      for (int j = 0; j <= 30; j++){
        int take = (1<<i);
        int give = (1<<j);
        if (1LL * a[p] + 1LL * take - 1LL * give == sum){
          mp[i-j]+=len;
          exist = 1;
          //printf("%d %d | ", i, j);
        }
      }
    }
    if (!exist)
      ok = 0;
    p = p2 - 1;
    //printf("\n");
  }

  for (auto i: mp){
    ok&=(mp[-i.first] == i.second);
    //printf("%d %d\n", i.first, i.second);
  }
  if (ok)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}