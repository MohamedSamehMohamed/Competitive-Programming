#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brR, brC;
    void dfs(vector<vector<int> >& land, int r, int c) {
        land[r][c] = 0;
        if (c > brC || r > brR) {
            brR = r;
            brC = c;
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int nr = dx[k] + r;
            int nc = dy[k] + c;
            if (nr >= 0 && nc >= 0 && nr < land.size() && nc < land[r].size() && land[nr][nc])
                dfs(land, nr, nc);
        }
    }
    vector<vector<int> > findFarmland(vector<vector<int> >& land) {
        vector<vector<int> > groups;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j]) {
                    brR = i;
                    brC = j;
                    dfs(land, i, j);
                    groups.push_back({i, j, brR, brC});
                }
            }
        }
        return groups;
    }
};