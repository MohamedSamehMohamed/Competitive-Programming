#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
void Sort(vector<int> v)
{
  for(auto i: v)cout << i <<" ";cout <<"\n";
  int len = v.size(), cnt = 0;
  for(int i = 0; i < len; i++)
    for(int j = 0; j < len; j++)
      if (v[i] < v[j])
      {
        swap(v[i], v[j]);
        cnt++;
      }
  printf("%d\n", cnt);
}
const int N = 1e5 + 9;
int a[N], n;
void test()
{
  for(int i = 0; i < 10; i++)
  {
    int len = 1 + rand() % 6; 
    vector<int> vv; 
    for(int j = 0; j < len; j++)
      vv.push_back(1 + rand() % 10);
    Sort(vv);
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
