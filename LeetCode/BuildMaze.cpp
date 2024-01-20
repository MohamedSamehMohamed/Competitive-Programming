#include <bits/stdc++.h>
using namespace std;

int get_random_number(int l, int r){
  return l + rand() % (r - l + 1);
}
vector<int> par;
int get_par(int u){
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void unit(int u, int v){
  u = get_par(u);
  v = get_par(v);
  if (u != v)
    par[u] = v;
}
bool same(int u, int v){
  return get_par(u) == get_par(v);
}
vector<vector<int>> gen_random_maze(int n, int m){
  int closed_room = 0;
  for (int i = 0; i < 4; i++)
    closed_room |= (1<<i);
  vector<vector<int>> grid(n, vector<int>(m, closed_room));
  par = vector<int> (n * m);
  for (int i = 0; i < n * m; i++)
    par[i] = i;
  int st_x = rand() % n, st_y = rand() % m;
  int en_x = rand() % n, en_y = rand() % m;
  while (st_x == en_x && st_y == en_y){
    en_x = rand() % n, en_y = rand() % m;
  }
  grid[st_x][st_y] |= (1<<4);
  grid[en_x][en_y] |= (1<<5);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<int> adj[n*m];
  vector<vector<int>> edges;
  // get all edges
  for (int i = 0; i < n * m; i++) {
    int r = i / m, c = i % m;
    for (int j = 0; j < 4; j++) {
      int nr = r + dx[j];
      int nc = c + dy[j];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      int v = nr * m + nc;
      edges.push_back({i, v});
    }
  }
  // build the tree
  int taken_edges = 0;
  while (taken_edges != n * m - 1){
    int index = rand() % (int)edges.size();
    int u = edges[index][0], v = edges[index][1];
    if (!same(u, v)){
      taken_edges++;
      adj[u].push_back(v);
      adj[v].push_back(u);
      unit(u, v);
    }
    swap(edges[index], edges.back());
    edges.pop_back();
  }
  // build the maze values
  for (int i = 0; i < n * m; i++){
    int cur_r = i / m, cur_c = i % m;
    for (int v: adj[i]){
      int v_r = v / m, v_c = v % m;
      cout << cur_r + 1 <<" " << cur_c + 1 <<" -> " << v_r + 1 <<" " << v_c + 1 <<"\n";
      for (int j = 0; j < 4; j++){
        if (cur_r + dx[j] == v_r && cur_c + dy[j] == v_c){
          grid[cur_r][cur_c] &= ~(1<<j);
          break;
        }
      }
    }
  }
  return grid;
}
vector<string> get_cell_shape(int value){
  vector<string> shape(3);
  shape[0] = "+0+";
  shape[1] = "000";
  shape[2] = "+0+";

  if (value & (1<<0)) {
    shape[0] = "+++";
  }
  if (value & (1<<1)) {
    shape[0][2] = shape[1][2] = shape[2][2] = '+';
  }
  if (value & (1<<2)) {
    shape[2] = "+++";
  }
  if (value & (1<<3)) {
    shape[0][0] = shape[1][0] = shape[2][0] = '+';
  }
  if (value & (1<<4)){
    shape[1][1] = 'S';
  }
  if (value & (1<<5)){
    shape[1][1] = 'E';
  }
  return shape;
}
int main(){
  int n = 3;
  int m = 4;
  auto maze = gen_random_maze(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << maze[i][j] <<" ";
    cout <<"\n";
  }
  vector<string> maze_draw(n * 3, "");
  int r_index = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      auto cell_shape = get_cell_shape(maze[i][j]);
      for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
          maze_draw[r_index+r]+= cell_shape[r][c];
        }
      }
    }
    r_index += 3;
  }
  for (int i = 0; i < 3 * n; i++) {
    for (int j = 0; j < maze_draw[i].size(); j++){
      if (j % 3 == 0 && j) cout << " ";
      cout << maze_draw[i][j];
    }

    cout <<"\n";
  }
}
