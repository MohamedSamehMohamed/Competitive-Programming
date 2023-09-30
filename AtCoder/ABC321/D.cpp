// Author : Mohamed Sameh
// created in: 2:25 PM
#include <bits/stdc++.h>
using namespace std;
int n, m, p;
void test(){
  cin >> n >> m >> p;
  vector<int> a(n), b(m);
  vector<long long> pre(m+1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  pre[0] = 0;
  for (int i = 0; i < m; i++)
    pre[i+1] = pre[i] + b[i];
  long long sum = 0;
  for (int i = 0; i < n; i++){
    int l = 0, r = m-1, mid, index = 0;
    while (l <= r){
      mid = (l+r) >> 1;
      if (a[i] + b[mid] <= p)
        index = mid+1, l = mid + 1;
      else
        r = mid - 1;
    }
    sum += 1LL * index * a[i] + pre[index] + 1LL * p * (m-index);
  }
  cout << sum <<"\n";
}
int main()
{
  test();
}