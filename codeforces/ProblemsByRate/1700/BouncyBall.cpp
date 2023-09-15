#include<bits/stdc++.h>
using namespace std;
int n, m, str, stc, enr, enc;
string d;
string dirs[4] = {"DR","DL","UR","UL"};
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
vector<int> dir;
bool canReach(){
  /*
  str + dir[0] * x = enr 
  stc + dir[1] * x = enc 
  x = enr - str/dir[0] 
  */
  int difR = enr - str;
  int difC = enc - stc;
  if (difR / dir[0] == difC / dir[1] && difR / dir[0] >= 0)
    return 1;
  return 0;
}
void test(){
  cin >> n >> m >> str >> stc >> enr >> enc >> d;
  for (int i = 0; i < 4; i++)
    if (d == dirs[i])
      dir = {dx[i], dy[i]};
  int bounce = 0;
  set<vector<int>> seen;
  while (true){
    if (seen.count({str, stc, dir[0], dir[1]}))
      break;
    seen.insert({str, stc, dir[0], dir[1]});
    if (canReach()){
      cout << bounce << "\n";
      return;
    }
    /*
      1 <= str + dir[0] * x <= n
      1 <= stc + dir[1] * x <= m
      
      1 - str <= dir[0] * x <= n - str 
     (1-str) / dir[0] <= x <= (n-str) / dir[0]
     
     (1-stc) / dir[1] <= x <= (m-stc) / dir[1]


    */
    int l = max( (1-str) / dir[0], (1 - stc) / dir[1] );
    int r = min( (n - str) / dir[0], (m-stc) / dir[1] );
    if (l > r)
      r = 0;
    str += dir[0] * r;
    stc += dir[1] * r;
    while (true){
      bool isBounce = 0;
      int oldr = str;
      int oldc = stc;
      str += dir[0];
      stc += dir[1];
      if (str < 1 || str > n){
        dir[0] *= -1;
        isBounce = 1; 
      }
      if (stc < 1 || stc > m){
        dir[1] *= -1;
        isBounce = 1;
      }
      if (isBounce){
        str = oldr;
        stc = oldc;
      }
      bounce += isBounce;
      if (isBounce){
        break;
      }
    }
  }
  cout << "-1\n";
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}