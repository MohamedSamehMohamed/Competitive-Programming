#include<bits/stdc++.h>
using namespace std;
int F(int x)
{
  int cur = 0;
  while(x)
  {
    cur += x % 10;
    x/=10;
    cur += 48;
  }
  return cur;
}
int main()
{
  for (int i = 1; i <= 20; i++)
  {
    int j = i;
    do
    {
      int cur = F(j);
      if (cur == j)break;
      j = cur;
    }while(1);
    cout << i << " " << j <<"\n";
  }
}
