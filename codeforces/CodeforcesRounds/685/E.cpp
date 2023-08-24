// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
double Distance(int n, int r)
{
  vector<double> a(n), b(n); double dist = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) dist += pow((a[i] - b[i]), r);
  return pow(dist, 1.0/r);
}
int main()
{
  
}
