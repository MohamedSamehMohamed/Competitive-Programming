#include<bits/stdc++.h>
using namespace std;
const int N = 27;
string s1, s2;
vector<vector<int>> quires;
int blockTime;
set<int> badPos;
void readInput(){
  quires.clear();
  badPos.clear();
  cin >> s1 >> s2;
  int q;cin >> blockTime >> q;
  while (q--){
    int type;cin >> type;
    if (type == 1){
      cin >> type;
      quires.push_back({1, type - 1});
    }else if (type == 2){
      int from, to, index1, index2;
      cin >> from >> index1 >> to >> index2;
      quires.push_back({2, from, index1 - 1, to, index2 - 1});
    }else {
      quires.push_back({3});
    }
  }
}
void checkForBadIndex(int index){
  if (s1[index] != s2[index]){
    badPos.insert(index);
  }else {
    badPos.erase(index);
  }
}
void doSwap(int ord1, int i, int ord2, int j){
  if (ord1 == ord2){
    if (ord1 == 1){
      swap(s1[i], s1[j]);
    }else {
      swap(s2[i], s2[j]);
    }
  }else {
    if (ord1 == 1){
      swap(s1[i], s2[j]);
    }else {
      swap(s2[i], s1[j]);
    }
  }
  checkForBadIndex(i);
  checkForBadIndex(j);
}
void solve(){
  int curTime = 0;
  priority_queue<vector<int>> pq;
  for (int i = 0; i < s1.size(); i++){
    if (s1[i] != s2[i])
      badPos.insert(i);
  }
  for (int i = 0; i < quires.size(); i++){
    while (!pq.empty() && -pq.top()[0] <= curTime){
      int index = pq.top()[1];
      pq.pop();
      if (s1[index] != s2[index])
        badPos.insert(index);
    }
    switch(quires[i][0]){
      case 1:
        pq.push({-curTime - blockTime, quires[i][1]});
        badPos.erase(quires[i][1]);
        break;
      case 2:
        doSwap(quires[i][1], quires[i][2], quires[i][3], quires[i][4]);
      break;
      case 3:
        bool ok = badPos.size() == 0;
        printf("%s\n", (ok? "Yes": "No"));
        break;
    }
    curTime++;
  }
}
int main(){
  int t;
  cin >> t;
  while (t--){
    readInput();
    solve();
  }
}