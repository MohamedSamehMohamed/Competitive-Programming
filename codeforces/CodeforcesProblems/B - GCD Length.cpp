#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a -= c;
    b -= c;
    string suf = "1" + string(c-1, '0');
    while(a--)printf("1");
    printf("%s", suf.c_str());
    printf(" ");
    while(b--)printf("3");
    printf("%s\n", suf.c_str());
  }
}
