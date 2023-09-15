// n consective sum of entertainment - (d * a + d + d + d + d ...
// sum - (d * a + d * (n-1)) => a last visit
// if subtract d from all
// sum - d * (a-1)
// take range [i:j] -> a[i] + a[i+1] + a[j] - (i-lstTakeIndex-1) *
// take a[i], a[i+2], a[i+5]
// a[i] + a[i+x] + a[i+y]  - ( x + y - x) * d -> (y * d)
// 3 2 5 4 6
// 1 0 3 2 4
// 0 1 2 3 4 5
// 1   1     1   -> (b-a-1) + (c-b-1) -> c - a - 2
// 1         1   -> (c-a-1)           -> c - a - 1
// startOfLastSegment - startOfFirstSegment - (number of segments-1)
// a b c (a+b+c)
//
// Author : Mohamed Sameh
// created in: 5:27 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, d;
int a[N];
void test(){
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
  }
  priority_queue<int> pq;
  long long sum = 0, mx = 0;
  for (int i = 0; i < n; i++){
    if (a[i] > 0)
    {
      sum += a[i];
      pq.push(-a[i]);
    }
    if (pq.size() > m){
      sum += pq.top();
      pq.pop();
    }
    mx = max(mx, sum - 1LL * (i+1) * d);
  }
  printf("%lld\n", mx);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}