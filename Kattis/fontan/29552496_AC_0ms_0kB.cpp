// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
char x[N][N]; 
int main()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i < n; i++)
  scanf(" %s", x[i]);
 for (int i = 0; i  + 1 < n; i++)
  for (int j = 0; j < m; j++)
  {
   if (x[i][j] != 'V')continue; 
   if (x[i+1][j] == '.')
    x[i+1][j] = 'V';
   if (x[i+1][j] == '#')
   {
    if (j+1 < m && x[i][j+1] == '.')x[i][j+1] = 'V'; 
    if (j-1 >= 0 && x[i][j-1] == '.')x[i][j-1] = 'V', j-=2;
   }
  }
 for (int i = 0; i < n; i++)
  printf("%s\n", x[i]); 
}
