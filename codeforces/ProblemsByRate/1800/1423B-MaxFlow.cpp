#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 9, INF = 1e9; 
int head[N],nxt[N],to[N],cap[N], cap2[N], parent[N], work[N], edgcnt=0;
int n, m;
void init()
{
    memset(head,-1,2 * (n+10)*sizeof(head[0]));
    edgcnt=0;
}
inline void addEdge(int f, int t, int c) {
    nxt[edgcnt] = head[f];
    to[edgcnt] = t;
    cap[edgcnt] = c;
    head[f] = edgcnt++;
}

inline void addAugEdge(int f, int t, int c) {
    addEdge(f, t, c);
    addEdge(t, f, 0);
}
int src, snk, limit;
int vis[N], dist[N], vid = 1;
inline int dfs(int u, int mn) {
    if (u == snk)
        return mn;
    vis[u] = vid;
    for (int &k = work[u]; ~k; k = nxt[k]) {
        int v = to[k], c = cap[k];
        if (!c || dist[v] != dist[u] + 1 || vis[v] == vid || c > limit) continue;  
        int f = dfs(v, min(c, mn));
        if (f) { 
            cap[k] -= f;
            cap[k ^ 1] += f;
            return f;
        }
    }
    return 0;
}

int q[N], qs;
inline bool bfs() {
    ++vid;
    q[0] = src;
    qs = 1;
    vis[src] = vid;
    dist[src] = 0;
    for (int f = 0; f < qs; f++) {
        int u = q[f];  
        for (int k = head[u]; ~k; k = nxt[k]) {
            int v = to[k];
            if (!cap[k] || vis[v] == vid || cap[k] > limit) continue;
            vis[v] = vid;
            dist[v] = dist[u] + 1;
            if (v == snk) return 1;
            q[qs++] = v;
        }
    }
    return 0;
}

inline int maxFlow() {
    
    for(int i = 0; i < N; i++)
      cap2[i] = cap[i];

    int res = 0;
    int flow = 0;
    while (bfs()) {
       memcpy(work, head, (2 * n + 10) * sizeof head[0]);
        do {
            ++vid;
            flow = dfs(src, 1e9);
            res += flow;
        } while (flow);
    }

    for(int i = 0; i < N; i++)
      cap[i] = cap2[i];
    
    return res;
}

bool can(int _limit)
{ 
  limit = _limit;
  int flow = maxFlow();
  return flow == n; 
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  scanf("%d%d", &n, &m);
  init();
  src = 0;
  snk = 2 * n + 1; 
  for(int i = 0; i < m; i++)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    v += n;
    addAugEdge(u, v, c); 
  }
  for(int i = 1; i <= n; i++)
  {
    addAugEdge(src, i, 1);
    addAugEdge(i+n, snk, 1); 
  }
  int l = 1, r = 1e9, mid, ans = -1;
  while(l <= r)
  {
    mid = (l+r) >> 1;
    if (can(mid))
      ans = mid, r = mid - 1; 
    else 
      l = mid + 1; 
  }
  printf("%d\n", ans);
}  
  