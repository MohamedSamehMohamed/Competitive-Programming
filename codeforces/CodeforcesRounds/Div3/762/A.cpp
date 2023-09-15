#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
char x[200];
int n;
void test()
{
  scanf(" %s", x); 
  n = strlen(x); 
  if (n % 2)
  {
    printf("No\n");
    return;
  }
  for(int i = n/2; i <= n/2; i++)
  {
    string a = "";
    string b = "";
    for(int j = 0; j < i; j++)
      a += x[j], b += x[i+j]; 
    if (a == b)
    {
      printf("Yes\n");
      return;
    } 
  }
  printf("No\n");
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
