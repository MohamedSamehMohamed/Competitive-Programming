#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[102];
void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  vector<int> dif;
  int sum = 0;
  for (int i = 0; i < n-1; i++)
  {
    sum += abs(a[i] - a[i+1]);
    dif.push_back(abs(a[i] - a[i+1]));
  }
  sort(dif.rbegin(), dif.rend());
  for (int i = 0; i < k-1; i++)
    sum -= dif[i];
  printf("%d\n", sum);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}