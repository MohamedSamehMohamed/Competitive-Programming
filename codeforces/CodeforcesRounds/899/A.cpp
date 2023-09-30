// Author : Mohamed Sameh
// created in: 3:25 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)cin >> v[i];
  int lst = 0;
  for (int i = 0; i < n; i++){
    if (v[i] != lst + 1)
      lst++;
    else
      lst+=2;
  }
  cout << lst <<"\n";
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}