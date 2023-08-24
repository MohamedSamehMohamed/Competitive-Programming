#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, c;
void test()
{
  scanf("%d%d", &n, &c); 
  vector<vector<int>> segments;
  for (int i = 0; i < n; i++)
  {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 > x2)
      swap(x1, x2), swap(y1, y2);
    segments.push_back({x1, y1, x2, y2});
  }
  sort(segments.begin(), segments.end());
  while(c--)
  {
    int x;scanf("%d",&x);
     
  }
}
int main()
{
  read_file();
  test();
}
