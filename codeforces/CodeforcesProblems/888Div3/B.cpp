// Author : Mohamed Sameh
// created in: 12:00 AM
#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  vector<int> v[2];
  vector<int> ord;
  for (int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    v[x%2].push_back(x);
    ord.push_back(x%2);
  }
  sort(v[0].rbegin(), v[0].rend());
  sort(v[1].rbegin(), v[1].rend());
  bool ok = 1;
  int lst = -1;
  for (int i = 0; i < n; i++){
    ok&= (v[ord[i]].back() >= lst);
    lst = v[ord[i]].back();
    v[ord[i]].pop_back();
  }
  if (ok)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}