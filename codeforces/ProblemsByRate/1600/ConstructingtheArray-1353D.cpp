// Author : Mohamed Sameh
// created in: 1:46 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  priority_queue<vector<int>> pq;
  pq.push({n, 0});
  int it = 1;
  while (pq.size()){
    auto cur = pq.top();
    pq.pop();
    int len = cur[0];
    int l = -cur[1];
    int r = l + len - 1;
    int sp = (len % 2 == 1? (l+r) >> 1: (l+r-1)>>1);
    a[sp] = it++;
    if (l <= sp-1)
      pq.push({sp-l, -l});
    if (sp + 1 <= r)
      pq.push({r-sp, -sp-1});
  }
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}