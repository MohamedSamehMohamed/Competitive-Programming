#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
int d[N], t[N], c[N];
long long chairs[N];
vector<int> checks[N];
int n, m;
bool can(int chairsPerDay){
  long long readyToMount = 0;
  long long doneCount = 0;
  for (int day = 0; day < n; day++){
    readyToMount += chairs[day];
    long long canBeMountToday = min(readyToMount,
         (long long)chairsPerDay);
    doneCount += canBeMountToday;
    readyToMount -= canBeMountToday;
    int lst = -1;
    for(int j: checks[day]){
      if (lst == -1)
        lst = j;
      if (lst != j){
        return 0;
      }
    }
     if (lst != -1) {
      long long undo = doneCount - lst;
      if (undo < 0) {
          return false;
      }

      doneCount = lst;
      readyToMount += undo;
    }
  }
}
int main(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d", d + i);
  for (int i = 0; i < m; i++)
    scanf("%d", t + i);
  for (int i = 0; i < m; i++)
    scanf("%d", c + i);
  for (int i = 0; i < m; i++){
    if (t[i] == 1)
      chairs[d[i] - 1] += c[i];
    else 
      checks[d[i] - 1].push_back(c[i]);
  }
  int l = 1, r = 1e9, mid, ans = -1;
  while (l <= r){
    mid = (l+r) >> 1;
    if (can(mid))
      ans = mid, r = mid - 1;
    else 
      l = mid + 1;
  }
  printf("%d\n", ans);
}