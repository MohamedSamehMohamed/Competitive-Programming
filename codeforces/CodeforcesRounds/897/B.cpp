// Author : Mohamed Sameh
// created in: 4:50 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n;
char s[N];
char out[N];
void test(){
  scanf("%d", &n);
  scanf(" %s", s);
  int dif = 0, same = 0;
  for (int i = 0; i < n - i - 1; i++){
    dif += (s[i] != s[n-i-1]);
    if (s[i] == s[n-i-1])same++;
  }
  for (int i = 0; i <= n; i++)
    out[i] = '0';

  if (dif == 0){
    out[0] = '1';
    for (int i = 1; i <= n; i++){
      if (i % 2 == 0)
        out[i] = '1';
      if (n % 2)
        out[i] = '1';
    }
  }

  out[dif] = '1';
  if (n % 2)
  {
    out[dif+1] = '1';
  }
  while (dif + 2 <= n && same > 0){
    dif += 2;
    out[dif] = '1';
    if (n % 2)
    {
      out[dif-1] = '1';
      out[dif+1] = '1';
    }
    same--;
  }
  for (int i = 0; i <= n; i++)
    printf("%c", out[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}