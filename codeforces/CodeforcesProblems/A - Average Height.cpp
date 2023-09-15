#include<bits/stdc++.h>
using namespace std;
void test()
{
  int n;scanf("%d", &n);
  vector<int> v[2];
  for (int i = 0, x; i < n; i++)
  {
    scanf("%d", &x);
    v[x%2].push_back(x);
  }
  for (int i: v[0])printf("%d ", i);
  for (int i: v[1])printf("%d ", i);
  printf("\n");
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)test();
}
