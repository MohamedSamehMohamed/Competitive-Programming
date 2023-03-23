#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n; 
int main()
{
  read_file();
  scanf("%d", &n);
  vector<array<int, 4>> v(n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d%d", &v[i][0], &v[i][1]);
    v[i][2] = v[i][3] = 0;  
  }  
  sort(v.begin(), v.end()); 
  for(int i = 1; i < n; i++)
  {
    if (v[v[i-1][2]][1] > v[i][1])
        v[i][2] = v[i-1][2];
    else 
        v[i][2] = i; 

    if (v[v[i-1][3]][1] < v[i][1])
        v[i][3] = v[i-1][3];
    else 
        v[i][3] = i; 
  }
  auto can = [&](long long dist)
  {
    for(int i = 0; i < n; i++)
    {
      long long max_x = v[i][0] - dist; 
      int l = 0, r = i-1, m, idx = -1;
      while(l <= r)
      {
        m = (l+r) >> 1;
        if (v[m][0] <= max_x)
          idx = m, l = m + 1;
        else 
          r = m-1; 
      }
      if (~idx)
      {
        int mx = v[v[idx][2]][1];
        int mn = v[v[idx][3]][1]; 
        if (abs(v[i][1] - mx) >= dist)return 1; 
        if (abs(v[i][1] - mn) >= dist)return 1;
      } 
    }
    return 0; 
  };
  long long l = 1, r = 1e9 + 20, m, ans = 0;
  while(l <= r)
  {
    m = (l+r) >> 1LL; 
    if (can(m))
      ans = m, l = m + 1; 
    else 
      r = m-1; 
  }
  printf("%lld\n", ans);
}