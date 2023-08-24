#include <bits/stdc++.h>
using namespace std;
long long k;
string s = "codeforces";
void test(){
  scanf("%lld", &k);
  vector<int> frq((int)s.size(), 1);
  long long prd = 1;
  int i = 0;
  while (prd < k){
    prd /= frq[i];
    frq[i]++;
    prd *= frq[i];
    i = (i+1) % ((int)s.size());
  }
  for (int i = 0; i < s.size(); i++){
    for (int j = 0; j < frq[i]; j++)
      printf("%c", s[i]);
  }
  printf("\n");
}
int main()
{
  test();
}