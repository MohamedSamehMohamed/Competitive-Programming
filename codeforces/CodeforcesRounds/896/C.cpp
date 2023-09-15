// Author : Mohamed Sameh
// created in: 4:33 PM
#include <bits/stdc++.h>
using namespace std;
int n, m;
void test(){
  scanf("%d%d", &n, &m);
  vector<set<int>> Row(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++)
    g[i] = vector<int>(m);
  for (int i = 0; i < m; i++){
    int cur = i == 0? 0: (g[0][i-1] + 1) % m;
    for (int j = 0; j < n; j++){
      int cnt = m;
      while (Row[j].count(cur) || cur == i){
        cur = (cur + 1) % m;
        cnt--;
        if (cnt == 0){
          break;
        }
      }
      g[j][i] = cur;
      Row[j].insert(cur);
      cur = (cur + 1) % m;
    }
  }
  set<int> total;
  for (int i = 0; i < m; i++){
    set<int> temp;
    for (int j = 0; j < n; j++){
      temp.insert(g[j][i]);
    }
    auto it = temp.begin();
    if (*it != 0){
//      cerr << 0 << " ";
      total.insert(0);
    }else {
      int cur = 1;
      it++;
      while (it != temp.end()){
        if (*it != cur)break;
        cur++;
        it++;
      }
//      cerr << cur << " ";
      total.insert(cur);
    }
//    cerr << "\n";
  }
  int mex = 0;
  auto it = total.begin();
  if (*it == 0){
    mex = 1;
    it++;
    while (it != total.end()){
      if (*it != mex)break;
      mex++;
      it++;
    }
  }
  printf("%d\n", mex);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", g[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}