#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const static int N = 1e3 + 2;
    bool seen[N];
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> boxes;
        memset(seen, 0, sizeof seen);
        for (int box: initialBoxes){
            boxes.push(box);
        }
        int maxCandies = 0;
        while (!boxes.empty()){
            int box = boxes.front();
            boxes.pop();
            if (status[box] == 0){
                if (!seen[box]){
                    seen[box] = 1;
                    boxes.push(box);
                }
                
                continue;
            }
            maxCandies += candies[box];
            for (int boxId : containedBoxes[box]){
                boxes.push(boxId);
            }
            for (int key : keys[box]){
                status[key] = 1;
            }
        }
        return maxCandies;
    }
};