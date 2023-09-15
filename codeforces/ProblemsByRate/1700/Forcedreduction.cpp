#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> adj[N];
string words[N];
char c[N];
int n;
set<string> cnt;
string path;
void dfs(int u, int p = -1){
  cnt.insert(path);
  for(int v: adj[u]){
    if (v == p) continue;
    string temp = path;
    path += words[v];
    dfs(v, u);
    path = temp;
  }
}
void solve(){
  scanf("%d", &n);
  path = "";
  for (int i = 1; i < n; i++){
    int v;
    scanf("%d %s", &v, c);
    adj[i].push_back(v-1);
    adj[v-1].push_back(i);
    words[i] = c;
  }
  dfs(0);
  printf("%d\n", cnt.size() - 1);
}
int main(){
  solve();
}