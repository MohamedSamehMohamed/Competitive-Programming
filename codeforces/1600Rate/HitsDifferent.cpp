#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long sum[N + 1];
void init(){
  sum[1] = 1;
  sum[2] = 5;
  sum[3] = 10;
  int num = 4;
  vector<int> prv_prv = {1};
  vector<int> prv = {2, 3};
  for (int i = 3; num <= N ; i++)
  {
    vector<int> cur;
    for (int j = 0; num <= N && j < i; j++)
    {
      sum[num] = 1LL * num * num;
      if (j-1 >= 0){
        sum[num] += sum[prv[j-1]];
      }
      if (j < prv.size()){
        sum[num] += sum[prv[j]];
      }
      if (j-1 >= 0 && j < prv.size()){
        sum[num] -= sum[prv_prv[j-1]];
      }
      cur.push_back(num);
      num++;
    }
    prv_prv = prv;
    prv = cur;
  }
}
int n;
void test(){
  scanf("%d", &n);
  printf("%lld\n", sum[n]);
}
int main(){
  init();
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}