// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 3e5 + 9;
int a[N], b[N], n;
int main()
{
  int t; scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i), b[i] = 0;
    int sum, mx;
    sum = mx = 0;
    for (int i = 1; i + 1 < n; i++)
    {
      if ((a[i] > max(a[i+1], a[i-1])) || (a[i] < min(a[i+1], a[i-1])))
      {
        b[i-1] += 1;
        b[i+1] += 1;
      }
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
      if (b[i] > mx)
      mx = b[i], idx = i;
    }
    a[idx] = (idx+1<n? (idx-1>=0?max(a[idx+1],a[idx-1]):a[idx+1]): a[idx-1]);
    // for (int i = 0; i < n; i++)cout << a[i] <<" \n"[i+1==n];
    for (int i = 1; i + 1 < n; i++)
    {
      if ((a[i] > max(a[i+1], a[i-1])) || (a[i] < min(a[i+1], a[i-1])))
        sum++;
    }
    printf("%d\n", sum);
  }
}
