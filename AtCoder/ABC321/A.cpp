// Author : Mohamed Sameh
// created in: 1:51 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  string x;
  cin >> x;
  for (int i = 1; i < x.size(); i++){
    if (x[i-1] <= x[i]){
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
}
int main()
{
  int t = 1;
  //scanf("%d", &t);
  while(t--)
    test();
}