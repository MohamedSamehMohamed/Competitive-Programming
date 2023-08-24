#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, x, y;
string fill(char c, int times)
{
  string s = "";
  while(times--)
    s+= c;
  return s;
}
string inv(string x)
{
  map<char, char> mp;
  mp['U'] = 'D';
  mp['D'] = 'U';
  mp['R'] = 'L';
  mp['L'] = 'R';
  for(int i = 0; i < x.size(); i++)
  {
    x[i] = mp[x[i]]; 
  }
  return x;
}
int mat[501][501], temp[501][501];
void check(string path)
{
  assert((int)path.size() <= 3 * (n-1)); 
  return; 
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      mat[i][j] = 1; 
  for(auto c: path)
  {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        temp[i][j] = mat[i][j];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
      {
        if (c == 'U')
        {
          if (i-1 >= 0)
          {
            temp[i-1][j] += mat[i][j]; 
            mat[i][j] = 0; 
          }
        }else if (c == 'D')
        {
          if (i + 1 < n)
          {
            temp[i+1][j] += mat[i][j];
            mat[i][j] = 0;
          }
        }else if (c == 'R')
        {
          if (j < n)
          {
            temp[i][j+1] += mat[i][j];
            mat[i][j] = 0;
          }
        }else 
        {
          if (j - 1 >= 0)
          {
            temp[i][j-1] += mat[i][j];
            mat[i][j] = 0;
          }
        }
      }
      for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        mat[i][j] = temp[i][j];
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << mat[i][j] <<" \n"[j == n-1];
}
void test()
{
  scanf("%d%d%d", &n, &x, &y);
  string path1 = "", path2 = "";
  path1 = fill('D', x - 1) + fill('R', y - 1);
  path2 = fill('U', n - x) + fill('L', n - y); 
  if (path1.size() == 0 || path2.size() == 0)
  {
    printf("%s\n", (path1 + path2).c_str()); 
    check(path1 + path2);
  }else 
  {
    if (path1.size() < path2.size())
      swap(path1, path2); 
    path1 += inv(path2) + path2;
    printf("%s\n",path1.c_str()); 
    check(path1);
  }
}
int main()
{
  read_file();
  int t;
  t = 1;
  //scanf("%d", &t);
  while(t--)
    test();
}
