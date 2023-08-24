#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9, LG = 24;
vector<int> adj[N];
int par[N][LG + 1], dep[N], sz[N];
int Par[N];

void dfs(int u, int p = 0) {
  par[u][0] = Par[u] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: adj[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int dist(int u, int v) {
  int l = lca(u, v);
  // cout <<"dist: ";
  // cout << u + 1 <<" " << v + 1 <<" ";
  // cout << dep[u] + dep[v] - (dep[l] << 1) <<"\n";
  
  return dep[u] + dep[v] - (dep[l] << 1);
}

int n, a[N], ti[N]; 

string ans;
int vis[N], vid;
int inTime[N];

void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  for(int i = 0; i < n; i++)
    scanf("%d", ti+i);
  ans = "";
  for(int i = 0; i < n; i++)
    adj[i].clear(), inTime[i] = -1;
  ans[0] = '1'; 
  for(int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  priority_queue<vector<int>> pq;
  vid++;
  pq.push({a[0], ti[0], 0});
  dfs(0, 0); 
  long long sum = 0;
  int curTime = 0;
  int lst = -1; 
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    if (vis[cur[2]] == vid)continue;
    vis[cur[2]] = vid; 
    int extraTime = 0;
    if (lst != -1)
    {
      extraTime = dist(lst, cur[2]); 
    }
     
    curTime += extraTime;
    
    if (cur[2] == 0 ||
       (curTime - inTime[Par[cur[2]]] <= ti[cur[2]]))
    {
      sum += a[cur[2]];
      lst = cur[2];
      inTime[cur[2]] = curTime; 
    }else 
    {
      curTime -= extraTime;
    }
    int old = pq.size();
    for(int i: adj[cur[2]])
    {
      if (vis[i] != vid)
        pq.push({a[i], ti[i], i});
    }
    if (pq.size() == old)
    {
      lst = cur[2];
      inTime[cur[2]] = curTime; 
    }
  }
  printf("%lld\n", sum);
 // calc(sum);
  //printf("%s\n", ans.c_str());
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
