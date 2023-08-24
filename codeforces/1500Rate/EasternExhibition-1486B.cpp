#include <bits/stdc++.h>
using namespace std;
int countMin(vector<int>& list){
  int n = list.size();
  return list[n/2] - list[(n-1)/2] + 1;
}
void fixIt(vector<int>& list){
  sort(list.begin(), list.end());
}
void test(){
  int n;
  scanf("%d", &n);
  vector<int> xList, yList;
  for (int i = 0; i < n; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    xList.push_back(x);
    yList.push_back(y);
  }
  fixIt(xList);
  fixIt(yList);
  printf("%lld\n", 1LL * countMin(xList) * countMin(yList));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}