#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, k, p, x, y;
int a[1000];
void test()
{
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  int sum = 0;
  for(int i = 0; i < k; i++)
    scanf("%d", a+i), sum += a[i];
  vector<vector<int>> v; 
  for(int i = 0; i < k; i++)
    v.push_back({a[i], 1}); 
  for(int i = 0; i < n - k; i++)
    v.push_back({1, 0}), sum++; 
  if (sum > x)
  {
    printf("-1\n");
    return;
  }
  sort(v.begin(), v.end()); 
  int mid = n / 2;
  bool can = 1;
  while(v[mid][0] < y && can)
  {
    can = 0;
    for(int i = 0; i < n; i++)
    {
      if (v[i][0] >= y)break;
      if (v[i][1] == 0)
      {
        if (v[i][0] < y && sum + (y - v[i][0]) <= x)
        {
          can = 1; 
          sum -= v[i][0];
          v[i][0] = y; 
          sum += v[i][0];
        }
      }
    }
    sort(v.begin(), v.end()); 
  }
  if (sum <= x && v[mid][0] >= y)
  {
    for(int i = 0; i < n; i++)
    {
      if (v[i][1] == 0)
        printf("%d ", v[i][0]);
    }
    printf("\n");
  }else 
  {
    printf("-1\n");
  }


}
int main()
{
  read_file();
  int t;
  //scanf("%d", &t);
  t = 1;
  while(t--)
    test();
}
