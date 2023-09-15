// Author : Mohamed Sameh
// created in: 5:20 PM
#include <bits/stdc++.h>
using namespace std;
int make_move(int x){
  cout << x << endl;
  int y;
  cin >> y;
  return y;
}
void test(){
  int n;
  cin >> n;
  int mex = 0;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    if (x == mex)
      mex++;
  }
  while (true){
    int y = make_move(mex);
    if (y <= -1)break;
    mex = y;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  while(t--)
    test();
}