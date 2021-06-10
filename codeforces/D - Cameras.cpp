// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9;
int n, k, r;
int a[N];
void PP()
{
  for (int i = 0; i < n; i++)
    cout << a[i] <<" ";
  cout <<"\n";
}
int main()
{
  scanf("%d%d%d", &n, &k, &r);
  for (int i = 0; i < k; i++)
  {
    int x;
    scanf("%d", &x);
    a[x-1] = 1;
  }
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < r-1; i++)
    sum += a[i];
  for (int i = 0, j = r-1; j < n; j++, i++)
  {
    sum += a[j];
    if (sum < 2)
    {
      ans += 2 - sum;
      int k = j;
      while(sum < 2)
      {
        if (a[k] == 0)
        {
          a[k] = 1;
          sum++;
        }
        k--;
      }
    }
    sum -= a[i];
  }
  printf("%d\n", ans);
}
