#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(vector<vector<int> >& grid, int r, int c, int pr = -1, int pc = -1) {
        int cnt = 4;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        grid[r][c] = 2;
        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr == pr && nc == pc) continue;
            bool isInside = nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[r].size();
            if (isInside && grid[nr][nc] == 1) {
                cnt += count(grid, nr, nc, r, c);
            }
            if (isInside && grid[nr][nc] == 3)
                cnt-=2;
        }
        grid[r][c] = 3;
        return cnt;
    }
    int islandPerimeter(vector<vector<int> >& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    perimeter += count(grid, i, j);
                }
            }
        }
        return perimeter;
    }
};
