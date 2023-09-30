// Author : Mohamed Sameh
// created in: 2:33 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], b[N], n, m;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  map<int, int> mp;
  map<int, vector<int>> pos;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int sz;scanf("%d", &sz);
    mp[sz]++;
  }
  bool need = 0;
  for (int i = 0; i < n; i++){
    if (a[i] < b[i]){
      printf("No\n");
      return;
    }
    if (a[i] != b[i]) need = 1;
  }
  if (!need){
    printf("Yes\n");
    return;
  }
  vector<int> values;
  set<int> skip;
  for (int i = 0; i < n; i++)
  {
    values.push_back(b[i]);
    pos[b[i]].push_back(i);
  }
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());

  for (int i = values.size()-1; i >= 0; i--){
    int parts = 1;
    int lst = -1;
    for (int j: pos[values[i]]){
      if (a[j] == b[j]) continue;
      if (lst == -1){
        lst = j;continue;
      }
      auto it = skip.lower_bound(lst+1);
      if (it != skip.end() && *it < j){
        parts++;
      }
      lst = j;
    }
    if (lst == -1)parts = 0;
    if (mp[values[i]] < parts){
      printf("No\n");
      return;
    }
    for (int j: pos[values[i]]){
      skip.insert(j);
    }
  }
  printf("Yes\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}