// Author : Mohamed Sameh
// created in: 12:45 AM
#include <bits/stdc++.h>
using namespace std;
int n, x, deg[1000];
void test(){
  scanf("%d%d", &n, &x);
  x--;
  memset(deg, 0, sizeof deg);
  for (int i = 1; i < n; i++){
    int u, v;scanf("%d%d", &u, &v);
    deg[--u]++;
    deg[--v]++;
  }
  if (n == 1 || deg[x] == 1 || n % 2 == 0)
    printf("Ayush\n");
  else
    printf("Ashish\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}