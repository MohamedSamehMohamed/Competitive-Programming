// Author : Mohamed Sameh
// created in: 1:19 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n, k;
void test(){
  scanf("%d%d", &n, &k);
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    mp[a[i]]++;
  }
  if (a[0] == a[n-1] && mp[a[0]] >= k){
    printf("Yes\n");
    return;
  }
  int cnt = 0, j = 0;
  for (int i = 0; j < 2 && i < n; i++){
    if (a[i] == a[0] && j == 0)
      cnt++;
    else if (a[i] == a[n-1] && j == 1)
      cnt++;
    if (cnt == k)
      j++, cnt = 0;
  }
  if (j == 2)
    printf("Yes\n");
  else
    printf("No\n");

}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}