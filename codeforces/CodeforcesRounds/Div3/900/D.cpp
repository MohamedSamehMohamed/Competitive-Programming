// Author : Mohamed Sameh
// created in: 4:56 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char s[N];
int n, k, L[N], R[N];
int A[N], rev[N], pre[N];
int seen[N];
void test(){
  scanf("%d%d", &n, &k);
  scanf(" %s", s);
  for (int i = 1; i <= k; i++)
    scanf("%d", L + i);
  for (int i = 1; i <= k; i++)
    scanf("%d", R + i);
  for (int i = 1; i <= k; i++){
    int cur = L[i];
    while (cur <= R[i]){
      A[cur] = i;
      cur++;
    }
  }
  for (int i = 0; i < n; i++) rev[i] = -1;
  for (int i = 0; i <= n; i++)pre[i] = 0;
  int q;
  scanf("%d", &q);
  vector<vector<int>> ranges;
  while (q--){
    int x;
    scanf("%d", &x);
    int i = A[x];
    int a = min(x, R[i] + L[i] - x);
    int b = max(x, R[i] + L[i] - x);
    a--;b--;
    ranges.push_back({a, b});
    pre[a+1]++;
    pre[b+2]--;
  }
  sort(ranges.begin(), ranges.end());
  stack<vector<int>> stk;
  stk.push(ranges[0]);
  for (int i = 1; i < ranges.size(); i++){
    if (stk.top()[1] < ranges[i][0])
      stk.push(ranges[i]);
    else
      stk.top()[1] = max(stk.top()[1], ranges[i][1]);
  }
  while (!stk.empty()){
    int l = stk.top()[0];
    int r = stk.top()[1];
    stk.pop();
    while (l <= r){
      rev[l]  = r;
      rev[r] = l;
      l++;r--;
    }
  }
  for (int i = 1; i <= n; i++)
    pre[i] += pre[i-1];

  for (int i = 0; i < n; i++) seen[i] = 0;
  for (int i = 0; i < n; i++){
    if (seen[i]) continue;
    if (pre[i+1]&1){
      swap(s[i], s[rev[i]]);
      seen[rev[i]] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%c", s[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}