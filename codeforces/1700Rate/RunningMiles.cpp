#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], sufMax[N], n;
void solve(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++){
    scanf("%d", a+i);
  }
  /*
    a[m] + a[r] + a[l] - (r-l)
    a[m] + a[r] + a[l] - r + l
    a[m] + (a[r] - r) + (a[l] + l)
  */
  sufMax[n] = a[n] - n;
  for (int i = n-1; i > 1; i--){
    sufMax[i] = max(sufMax[i+1], a[i] - i);
  }
  int preMax = a[1] + 1;
  int ans = 0;
  for(int i = 2; i < n; i++){
    ans = max(ans, a[i] + preMax + sufMax[i+1]);
    preMax = max(preMax, a[i] + i);
  }
  printf("%d\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}
