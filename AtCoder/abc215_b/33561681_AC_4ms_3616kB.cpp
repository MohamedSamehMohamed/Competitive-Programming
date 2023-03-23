#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int main()
{
  read_file();
  long long n;
  cin >> n;
  int k = 0;
  long long cur = 1; 
  while(cur <= n)
  {
    cur *= 2LL; 
    k++; 
  } 
  cout << k-1 <<"\n"; 
}
