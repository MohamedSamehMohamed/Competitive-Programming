#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n; scanf("%d", &n);
    int up = 0;
    for (int i = 0; i < n; i++)
    {
      int ty;scanf("%d", &ty);
      if (ty == 1)up++;
      if (ty == 3)
        up++;
 
    }
    printf("%d\n", up);
  }
}
