#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  vector<vector<int>> segs;
  for (int i = 0; i < n; i++){
    int j = i + 1;
    while (j < n && a[j] > a[j-1])
      j++;
    segs.push_back({a[i], a[j - 1]});
    i = j - 1;
  }
  int l = 0, r = segs.size()-1;
  while (l < r){
    int nex = l + 1;
    while (nex <= r && segs[l][0] > segs[nex][1])
      nex++;
    if (nex > r) break;
    swap(segs[l], segs[nex]);
    l = nex;
  }
  if (l == r)
    printf("YES\n");
  else
    printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}