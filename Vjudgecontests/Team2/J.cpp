// Author : Mohamed Sameh
// created in: 11:46 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n, k;
  scanf("%d%d", &n, &k);
  int sum = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++){
    int x;scanf("%d", &x);
    sum += x;
    pq.push(-x);
    while (pq.size() > k){
      sum += pq.top();
      pq.pop();
    }
  }
  printf("%d\n", sum);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}