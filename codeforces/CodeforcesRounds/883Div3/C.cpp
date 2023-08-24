#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, h;
int a[N];
void test(){
  scanf("%d%d%d", &n, &m, &h);
  vector<vector<long long>> rank;
  for (int i = 0; i < n; i++){
    
    for (int j = 0; j < m; j++)
      scanf("%d", a+j);
    
    sort(a, a+m);
    int solved = 0;
    long long pen = 0, curTime = 0;
    for (int j = 0; j < m; j++){
      if (curTime + a[j] > h) break;
      solved++;
      curTime += a[j];
      pen += curTime;
    }
    rank.push_back({solved, pen, i + 1});
  }
  sort(rank.begin(), rank.end(), [](vector<long long>& A, vector<long long>& B){
    if (A[0] != B[0])
      return A[0] > B[0];
    if (A[1] != B[1])
      return A[1] < B[1];
    return A[2] < B[2];
  });
  for (int i = 0; i < n; i++){
    if (rank[i][2] == 1){
      printf("%d\n", i + 1);
      return;
    }
  }
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}