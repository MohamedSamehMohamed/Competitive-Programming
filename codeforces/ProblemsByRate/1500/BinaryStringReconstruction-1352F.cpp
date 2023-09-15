#include <bits/stdc++.h>
using namespace std;
int a[3];
void test(){
  for (int i = 0; i < 3; i++)
    scanf("%d", a + i);
  string out[] = {"", "", ""};
  string base[] = {"00", "10", "11"};
  for (int i = 0; i < 3; i++){
    if (a[i]){
      out[i] += base[i];
      for (int j = 1; j < a[i]; j++)
        out[i] += base[i][(j+1)%2];
    }
  }
  string result = "";
  // 00 11 10
  if (a[0] && a[1] && a[2]){
    out[1].pop_back();
    out[2].pop_back();
  }else if (a[1] && a[2]){
    out[2].pop_back();
  }else if (a[0] && a[1]){
    out[1].pop_back();
  }
  result = out[0] + out[2] + out[1];
  printf("%s\n", result.c_str());
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
