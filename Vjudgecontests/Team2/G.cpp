// Author : Mohamed Sameh
// created in: 11:17 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 9;
int n, m, k;
vector<int> adj[N];
int fun[N];
long long ans;
int temp[N], dist[N];
struct Node {
  int node;
  long long sum;
  priority_queue<int> pq;
  Node(int st){
    node = st;
    sum = 0;
    pq = priority_queue<int>();
    pq.push(-fun[st]);
    sum += fun[st];
    process();
  }
  Node(int st, priority_queue<int>& ref){
    int index = 0;
    node = st;
    sum = 0;
    while (!ref.empty()){
      temp[index++] = ref.top();
      sum += -temp[index-1];
      pq.push(temp[index-1]);
      ref.pop();
    }
    for (int i = 0; i < index; i++)
      ref.push(temp[i]);
    pq.push(-fun[st]);
    sum += fun[st];
    process();
  }
  void process(){
    while ((pq.size() > k) || (pq.size() > 0 && -pq.top() <= 0))
    {
      sum -= -pq.top();
      pq.pop();
    }
  }
};
void startFrom(int u){
  queue<Node> q;
  memset(dist, -1, sizeof dist);
  q.push(Node(u));
  dist[u] = 0;
  while (!q.empty()){
    auto cur = q.front();
    q.pop();
    u = cur.node;
    if (dist[u] == m)continue;
    ans = max(ans, cur.sum);
    for (int v: adj[u]){
      if (dist[v] == -1){
        dist[v] = dist[u] + 1;
        Node newNode = Node(v, cur.pq);
        q.push(newNode);
      }
    }
  }
}
void test(){
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  for (int i = 0; i < n; i++)
    scanf("%d", fun + i);
  for (int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  for (int i = 0; i < n; i++)
    startFrom(i);
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}