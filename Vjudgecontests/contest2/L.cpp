// Author : Mohamed Sameh
// created in: 10:55 PM
#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  vector<vector<int>> v;
  for (int i = 0; i < n; i++){
    int l, r, t;
    scanf("%d%d%d", &t, &l, &r);
    v.push_back({l, r, t});
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++){
      if (v[i][0] > v[j][1] || v[i][1] < v[j][0]) continue;
      if (v[i][0] == v[j][1]){
        // j i
        if (v[i][2] == v[j][2] && v[i][2] == 1)
          ans++;
        else if (v[j][2] == 1 && v[i][2] == 2)
          ans++;
        else if (v[j][2] == 3 && v[i][2] == 1)
          ans++;
      }else if (v[i][1] == v[j][0]){
        // i j
        if (v[i][2] == v[j][2] && v[i][2] == 1)
          ans++;
        else if (v[i][2] == 1 && v[j][2] == 2)
          ans++;
        else if (v[i][2] == 3 && v[j][2] == 1)
          ans++;
      }else
        ans++;
    }
  }
  printf("%d\n", ans);
}
int main()
{
  test();
}