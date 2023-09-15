#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m;
char s[N], t[N];
vector<int> l, r;
void test(){
  scanf("%d%d %s %s", &n, &m, s, t);
  for (int i = 0, j = 0; i < m; i++){
    while (s[j] != t[i])
      j++;
    l.push_back(j);
    j++;
  }
  for (int i = m-1, j = n-1; i >= 0; i--){
    while (s[j] != t[i])
      j--;
    r.push_back(j);
    j--;
  }
  reverse(r.begin(), r.end());
  int ans = 1;
  for (int i = 0; i < m - 1; i++){
    ans = max(ans, r[i+1] - l[i]);
  }
  printf("%d\n", ans);
}
int main()
{
  test();
}