#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e6 + 9;
int n, m;
char x[N];
void test()
{
  scanf("%d%d %s", &n, &m, x);
  int len = strlen(x);
  int l = 0, r = len, mid, ans = 0;
  int dx = 1, dy = 1; 
  auto can = [&](int mx)
  {
    int cx = 0, cy = 0;
    dx = 0, dy = 0;
    int msk0, msk1;
    msk0 = 0;
    msk1= 0;
    for(int i = 0; i < mx; i++)
    {
      if (x[i] == 'L')
      {
        cy--;
        if (cy == m-1)msk0 |=(1<<1); 
        if (cy == -(m-1))msk0|=(1<<2); 
        if (abs(cx) >= n-1 || abs(cy) >= m-1)return 0; 
        if (cy < 0)
        {
          dy++;
          cy++;
        }
      }else if (x[i] == 'R')
      {
        cy++;
        if (cy == m-1)msk0 |=(1<<1); 
        if (cy == -(m-1))msk0|=(1<<2); 
        if (abs(cx) >= n-1 || abs(cy) >= m-1)return 0; 
      }else if (x[i] == 'D')
      {
        cx++;
        if (cx ==n-1)msk1 |=(1<<1); 
        if (cx == -(n-1))msk1|=(1<<2); 
        if (abs(cx) >= n-1 || abs(cy) >= m-1)return 0; 
      }else 
      {
        cx--;
        if (cx ==n-1)msk1 |=(1<<1); 
        if (cx == -(n-1))msk1|=(1<<2); 
        if (abs(cx) >= n-1 || abs(cy) >= m-1)return 0; 
        if (cx < 0) 
        {
          dx++;
          cx++;
        }
      }
      
    }
    return 1; 
  };
  while(l <= r)
  {
    mid = (l+r) >> 1;
    if (can(mid))
    {
      ans = mid;
      l = mid + 1;
    }else 
      r = mid - 1;
  }
  can(ans); 
  printf("%d %d\n", dx + 1, dy + 1); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
