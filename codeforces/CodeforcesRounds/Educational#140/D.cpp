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
int answer[N];
int solve(int n)
{
  if (answer[n] != -1)
    return answer[n];
  answer[n] = 0;
  // w + 2x^2 + 3y^3 + 4z^4 = n 
  // 2x^2 + 3y^3 + 4z^4 = n - w 
  for(int y = 0; 3LL * y * y * y <= n; y++)
  {   
    for(int z = 0; 4LL * z * z * z * z <= n; z++)
    {
      if (3LL * y * y * y + 4LL * z * z * z * z > n)
        break;
      int l = 0, r = n, mid, x = 0;
      while(l <= r)
      {
        mid = (l+r) >> 1; 
        if (2LL * mid * mid  + 3LL * y * y * y 
          + 4LL * z * z * z * z <= n)
          x = mid, l = mid + 1; 
        else 
          r = mid - 1;
      }
      answer[n]+=x+1;
    }
  }
  return answer[n];
}
void test()
{
  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n));
}
int main()
{
  memset(answer, -1, sizeof answer);
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
