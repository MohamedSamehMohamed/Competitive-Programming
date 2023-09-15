// Author : Mohamed Sameh
// created in: 4:37 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  vector<int> out;
  out.push_back(a[0]);
  for (int i = 1; i < n; i++){
    if (a[i] >= out.back())
      out.push_back(a[i]);
    else
    {
      out.push_back(a[i]);
      out.push_back(a[i]);
    }
  }
  printf("%d\n", (int)out.size());
  for(int i: out) printf("%d ", i);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}