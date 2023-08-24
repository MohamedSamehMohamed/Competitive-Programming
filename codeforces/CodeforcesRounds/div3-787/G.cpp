#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 260;
int n, m;
int a[N], b[N];
int have[N];
int solve(int st)
{

}
void test()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", a + i);
  int answer = 1e9;
  for(int st = 1; st <= m; st++)
    answer = min(answer, solve(st));
  printf("%d\n", answer);
}
int main()
{
  read_file();
  test();
}
