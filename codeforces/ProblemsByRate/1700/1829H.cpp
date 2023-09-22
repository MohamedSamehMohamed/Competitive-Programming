// Author : Mohamed Sameh
// created in: 7:01 AM
#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 6, mod = 1e9 + 7;
int cnt[M], n, k;
int masks[M], temp[M];
void calc(int x){
  memset(temp, 0, sizeof temp);
  temp[x]++;
  for (int i = 0; i < M; i++){
    if (masks[i])
      temp[i&x] = (temp[i&x] + masks[i])%mod;
  }
  for (int i = 0; i < M; i++)
    masks[i] = (masks[i] + temp[i])%mod;
}
void test(){
  scanf("%d%d", &n, &k);
  memset(masks, 0, sizeof masks);
  int x;
  for (int i = 0; i < n; i++){
    scanf("%d", &x);
    calc(x);
  }
  int ans = 0;
  for (int i = 0; i < M; i++)
  {
    if (cnt[i] == k)
      ans = (ans + masks[i])%mod;
  }
  printf("%d\n", ans);
}
int main()
{
  for (int i = 0; i < M; i++){
    for (int j = 0; j < 6; j++)
      cnt[i] += ((i & (1<<j)) != 0);
  }
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}