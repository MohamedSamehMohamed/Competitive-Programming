// Author : Mohamed Sameh
// created in: 1:57 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9, mod = 1e9 + 7;
vector<int> adj[N];
int n;
int dp[N][N];
int solve(int u, int rm, int parentIsPaint = 0, int currentIsPaint = 1){

}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp, -1, sizeof dp);
  for (int i = n; i >= 0; i--){
    printf("%d\n", solve(0, n - i));
  }
}
int main()
{
  test();
}