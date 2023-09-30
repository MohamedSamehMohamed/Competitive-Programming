// Author : Mohamed Sameh
// created in: 4:42 PM
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[55], b[55];
void test(){
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < m; i++)
    scanf("%d", b+i);
  sort(a, a+n);
  sort(b, b+m);
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  vector<long long> cyc;
  for (int i = 0; i < 2; i++){
    if (i % 2 == 0){
      if (a[0] < b[m-1]){
        sum -= a[0];
        sum += b[m-1];
        swap(a[0], b[m-1]);
      }
    }else {
      if (b[0] < a[n-1]){
        sum -= a[n-1];
        sum += b[0];
        swap(b[0], a[n-1]);
      }
    }
    sort(a, a+n);
    sort(b, b+m);
    cyc.push_back(sum);
  }
  swap(cyc[0], cyc[1]);
  printf("%lld\n", cyc[k%2]);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}