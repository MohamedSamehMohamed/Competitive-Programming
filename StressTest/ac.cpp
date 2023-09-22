#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int M = (1 << 13) + 10;

int mex[N][N];
vector<bool> dp[N];
int pos[M];

int main() {
  for (int i = 0; i < N; i++) {
    dp[i].resize(M);
  }
  int tt;
  cin >> tt;
  /*
  tt = 1;
  */
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> was(n + 1, -1);
    vector<vector<pair<int, int>>> g(n);
    for (int i = n - 1; i >= 0; i--) {
      int k = 0;
      for (int j = i; j < n; j++) {
        was[a[j]] = i;
        while (k < n && was[k] == i) {
          k += 1;
        }
        mex[i][j] = k;
        if (i == j || (mex[i][j] > mex[i][j - 1] && mex[i][j] > mex[i + 1][j])) {
          g[i].emplace_back(j, mex[i][j]);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < M; j++) {
        dp[i][j] = false;
      }
    }
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
      int cc = 0;
      for (int j = 0; j < M; j++) {
        if (dp[i][j]) {
          dp[i + 1][j] = true;
          pos[cc++] = j;
        }
      }
      for (auto& p : g[i]) {
        int to = p.first + 1;
        int v = p.second;
        for (int jt = 0; jt < cc; jt++) {
          dp[to][pos[jt] ^ v] = true;
        }
      }
    }
    for (int j = M - 1; j >= 0; j--) {
      if (dp[n][j]) {
        cout << j << '\n';
        break;
      }
    }
  }
  return 0;
}
