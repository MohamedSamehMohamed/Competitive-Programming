#include<bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
  scanf("%d%d", &n, &k);
  string x = "";
  for (int i = 0; i < k; i++)
    for (int j = i; j < k; j++)
    {
      x += char('a' + i);
      x += char('a' + j);
    }
  for (int i = 0; i < n; i++)
    printf("%c", x[i % (int)x.size()]);
  printf("\n");
}
