#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char c[N];
int n;
int frq[26], pairList[26][26];
void solve(){
  scanf("%d %s", &n, c);
  
  memset(frq, 0, sizeof frq);
  memset(pairList, 0, sizeof pairList);
  bool ok = (n % 2 == 0);
  for (int i = 0; ok && i < n; i++)
  {
    frq[c[i] - 'a']++;
    ok &= (frq[c[i] - 'a'] <= n / 2);
  }
  if (!ok){
    printf("-1\n");
    return;
  }
  for (int i = 0; i < n / 2; i++){
    int u = c[i] - 'a';
    int v = c[n-i-1] - 'a';
    pairList[u][v]++;
  }
  int ans = 0;
  priority_queue<int> pq;
  for (int i = 0; i < 26; i++){
    if (pairList[i][i])
      pq.push(pairList[i][i]);
  }
  while (pq.size() > 1){
    int f = pq.top();pq.pop();
    int s = pq.top();pq.pop();
    ans++;
    f--;s--;
    if (f)
      pq.push(f);
    if (s)
      pq.push(s);
  }
  if (pq.size())
    ans += pq.top();
  printf("%d\n", ans);

}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}

