int solve(){
  vector<vector<int>> paths;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      paths.push_back(get_path(i, j));
    }
  }
  int len = paths.size();
  long long cnt = 0;
  for (int i = 0; i < len; i++){
    for (int j = i + 1; j < len; j++){
      cnt = (cnt + calc(paths[i], paths[j])%mod)%mod;
    }
  }
  return cnt;
}
int calc(vector<int>&a, vector<int>&b){
  int cnt = 0;
  for (int i: a){
    for (int j: b){
      if (i == j)
      {
        cnt++;
        break;
      }
    }
  }
  return cnt;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long upper) {
  return rng() % upper;
}
int dsu[N];
int get_par(int u){
  return u == dsu[u]? u: dsu[u] = get_par(dsu[u]);
}
void connect(int u, int v){
  u = get_par(u);
  v = get_par(v);
  if (u != v)
    dsu[u] = v;
}
void testAgainst(){
  n = 2 + myRand(100);
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    dsu[i] = i;
    subSum[i] = 0;
  }
  vector<vector<int>> tree;
  for (int i = 1; i < n; i++){
    int j = myRand(n);
    while (get_par(i) == get_par(j)){
      j = myRand(n);
    }
    adj[i].push_back(j);
    adj[j].push_back(i);
    connect(i, j);
    tree.push_back({i + 1, j + 1});
  }
  ans = 0;
  dfs();
  count();
  int ans2 = solve();
  if (ans != ans2){
    cout << ans <<" " << ans2 <<"\n";
    cout << n <<"\n";
    for (auto ii: tree){
      cout << ii[0] <<" " << ii[1] <<"\n";
    }
    exit(0);
  }else {
    cout <<"passed\n";
  }
}
vector<int> get_path(int u, int v){
  queue<int> q;
  q.push(u);
  vector<int> par(n, -1);
  par[u] = u;
  while (!q.empty()){
    u = q.front();
    q.pop();
    for (int vv: adj[u]){
      if (par[vv] == -1){
        par[vv] = u;
        q.push(vv);
      }
    }
  }
  vector<int> path;
  while (par[v] != v){
    path.push_back(v);
    v = par[v];
  }
  path.push_back(v);
  reverse(path.begin(), path.end());
  return path;
}
