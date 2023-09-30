// Author : Mohamed Sameh
// created in: 11:24 PM
#include <bits/stdc++.h>
using namespace std;
int toOneD(int r, int c, int width){
  return r * width + c;
}
void toTwoD(int one, int width, int& r, int& c){
  r = one / width;
  c = one % width;
}
int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY,
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize){
  // base case if start = end
  if (nStartX == nTargetX && nStartY == nTargetY)
    return 0;
  queue<int> q;
  int start = toOneD(nStartY, nStartX, nMapWidth);
  q.push(start);
  vector<int> par (nMapWidth * nMapHeight, -1);
  par[start] = start;
  while (!q.empty()){
    int current = q.front();
    q.pop();
    int r, c;
    toTwoD(current, nMapWidth, r, c);
    // check adjacent
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++){
      int nr = r + dx[i];
      int nc = c + dy[i];
      // check if it is out of the grid,
      if (nr < 0 || nc < 0 || nr >= nMapHeight || nc >= nMapWidth) continue;
      int one = toOneD(nr, nc, nMapWidth);
      // check if visited before and valid to go
      if (par[one] == -1 && pMap[one]== 1){
        par[one] = current;
        q.push(one);
      }
    }
  }
  int target = toOneD(nTargetY, nTargetX, nMapWidth);
  // can't reach the target cell
  if (par[target] == -1){
    return -1;
  }

  // construct the path from parent array
  vector<int> path;
  while (par[target] != target){
    path.push_back(target);
    target = par[target];
  }
  for (int i = 0; i < min(nOutBufferSize,(int)path.size()); i++){
    pOutBuffer[i] = path[path.size()-i-1];
  }
  return path.size();
}
