#include<bits/stdc++.h>
using namespace std;
int n, q;
int pos[51];
void test()
{
  scanf("%d%d", &n, &q);
  memset(pos, -1, sizeof pos);
  for(int i = 0, x; i < n; i++)
  {
    scanf("%d", &x);
    if (pos[x] == -1)pos[x] = i;
  }
  while(q--)
  {
    int x;scanf("%d", &x);
    printf("%d ", pos[x] + 1);
    int tem = pos[x];
    pos[x] = -1;
    for (int i = 1; i <= 50; i++)
      if (pos[i] < tem)
        pos[i]++;
  }
  printf("\n");
}
int main()
{
  test();
}
