#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  int sum = 0;
  for (int i = 0; i < n / 2; i++){
    sum += a[n-i-1] - a[i];
  }
  printf("%d\n", sum);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
}