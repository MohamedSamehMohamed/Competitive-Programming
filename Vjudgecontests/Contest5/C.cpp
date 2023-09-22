// Author : Mohamed Sameh
// created in: 9:34 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char s[N];
int n;
void test(){
  scanf(" %s", s);
  n = strlen(s);
  vector<int> one;
  for (int i = 0; i < n; i++){
    if (s[i] == '1')
      one.push_back(i);
  }
  for (int i = 0; i < one.size(); i++){
    int prv = i? one[i-1]: -1;
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}