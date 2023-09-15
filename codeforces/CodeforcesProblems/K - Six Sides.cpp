// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int a[6][2];
  for (int j = 0; j < 2; j++)
    for (int i = 0; i < 6; i++)
      cin >> a[i][j];
  int tot = 0;
  int win = 0;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (a[i][0] > a[j][1])
        win++;
      if (a[i][0] != a[j][1])
        tot++; 
    }
  }
  printf("%.5f\n", 1.0*win/tot);
}
