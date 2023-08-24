#include <bits/stdc++.h>
using namespace std;
int r, x, y, x2, y2;
void test(){
  scanf("%d%d%d%d%d", &r, &x, &y, &x2, &y2);
  long long dist = 1LL * (x-x2) * (x-x2) + 1LL * (y-y2) * (y-y2);
  long long sdist = sqrt(dist);
  while ((sdist+1) * (1+sdist) <= dist)
    sdist++;
  int steps = (sdist + 2LL*r - 1) / (2LL * r);
  steps += (sdist * sdist) < dist && (sdist % (2LL * r) == 0);
  printf("%d\n", steps);
}
int main()
{
  test();
}