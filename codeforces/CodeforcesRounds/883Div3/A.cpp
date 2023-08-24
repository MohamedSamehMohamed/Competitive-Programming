#include<bits/stdc++.h>
using namespace std;
int n;
void test(){
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    if (a - b > 0)
      ans++;
  }
  printf("%d\n", ans);

}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}