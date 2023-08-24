// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
char x[100009];
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n; scanf("%d", &n);
    scanf(" %s", x);
    int lst = -1;
    for (int i = 0; i < n; i++)
    {
      if (x[i] == '0')
      {
        if (lst != 1)
        {
          printf("1");
          lst = 1;
        }else
        {
          printf("0");
          lst = 0;
        }
      }else
      {
        if (lst != 2)
        {
          printf("1");
          lst = 2;
        }else
        {
          printf("0");
          lst = 1;
        }
      }
    }
    printf("\n");
  }
}
