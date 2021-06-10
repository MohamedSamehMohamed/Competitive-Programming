#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int t, n;
char a[3][N];
bool isZero(char c)
{
  return c == '0';
}
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < 3; i++)scanf("%s", a[i]);
  string answer = "";
  int pos[3] = {0};
  while(answer.size() < 3 * n && min({pos[0], pos[1], pos[3]}) < 2 * n)
  {
    int zero, one;
    zero = one = 0;
    for (int i = 0; i < 3; i++)
      if (pos[i] < 2 * n)
        zero += isZero(a[i][pos[i]]) * (pos[i]+1), one += !isZero(a[i][pos[i]]) * (pos[i]+1);
    if (zero > one)
      answer += '0';
    else
      answer += '1';
    for (int i = 0; i < 3; i++)
      if (pos[i] < 2 * n && a[i][pos[i]] == answer.back())
        pos[i]++;
  }
  printf("%s\n", answer.c_str());
}
int main()
{
  scanf("%d", &t);
  while(t--)test();
}
