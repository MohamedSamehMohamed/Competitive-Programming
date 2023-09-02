// Author : Mohamed Sameh
// created in: 6:31 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 509;
int n, m;
string board[N];
char temp[N];
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++){
    scanf(" %s", temp);
    board[i] = temp;
  }
  bool can = 1;
  for (int i = 0; i < n; i++){
    int ud = 0;
    for (int j = 0; j < m; j++){
      if (board[i][j] == 'U'){
        board[i][j] = (ud? 'B': 'W');
        board[i+1][j] = (ud? 'W': 'B');
        ud ^= 1;
      }
    }
    can &= ud == 0;
  }
  for (int i = 0; i < m; i++){
    int lr = 0;
    for (int j = 0; j < n; j++){
      if (board[j][i] == 'L'){
        board[j][i] = (lr? 'B': 'W');
        board[j][i+1] = (lr? 'W': 'B');
        lr ^= 1;
      }
    }
    can &= lr == 0;
  }
  if (!can){
    printf("-1\n");
    return;
  }
  for (int i = 0; i < n; i++){
    printf("%s\n", board[i].c_str());
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}