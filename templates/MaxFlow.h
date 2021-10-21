#include <bits/stdc++.h>
using namespace std;
#define neigh(u,e,v) for(int e=head[u],v;~e&&(v=to[e],1);e=nxt[e])
const int N = 8e6 + 9, MXFlow = 20, mod = 1e9+7;
int vis[N], vid, n;
long long Answer[N];
int head[N],nxt[N],to[N],cap[N],edgcnt=0;
void init()
{
    memset(head,-1,n*sizeof(head[0]));
    edgcnt=0;
}
void addEdge(int a,int b,int c)
{
    nxt[edgcnt]=head[a];
    to[edgcnt]=b;
    cap[edgcnt]=c;
    head[a]=edgcnt++;
}


const int INF = 1e9;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



// class Matching 
class matching
{
  vector<vector<int>> adj;
  vector<int> match_a, match_b, seen; 
  int n, m, vis_id;
  int flow; 
  
  public:
    matching(int _n, int _m): n(_n), m(_m)
    {
      adj.resize(n);
      match_a = vector<int>(n, -1);
      match_b = vector<int>(m, -1); 
      seen = vector<int> (n, 0);  
      flow = 0;
      vis_id = 0;
    }
    void add(int u, int v)
    {
      assert(u >= 0 && u < n && v >= 0 && v < m); 
      adj[u].push_back(v); 
    } 
    bool dfs(int u)
    {
      seen[u] = vis_id; 
      for(int v: adj[u])
        if (match_b[v] == -1)
        {
          match_b[v] = u; 
          match_a[u] = v; 
          return 1; 
        }
      for(int v: adj[u])
        if (seen[match_b[v]] != vis_id && dfs(match_b[v]))
        {
          match_b[v] = u; 
          match_a[u] = v; 
          return 1; 
        }
      return 0; 
    }
    int maxflow()
    {
      while(true)
      {
        vis_id++; 
        int cur_flow = 0;
        for(int i = 0; i < n; i++)
        {
          if (match_a[i] == -1 && dfs(i))
            cur_flow++; 
        }
        if (cur_flow == 0)
          break; 
        flow += cur_flow; 
      }
      return flow; 
    }
};
