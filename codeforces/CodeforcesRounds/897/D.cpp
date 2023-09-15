// Author : Mohamed Sameh
// created in: 6:29 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], n, k;
const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;

struct data
{
  int l, r, idx;
}qr[Q];
int q;
int frq[M];
long long ans[Q];
long long cur = 0;

bool comp(struct data &d1, struct data &d2)
{
  int b1 = d1.l / SZ;
  int b2 = d2.l / SZ;
  if(b1 != b2)
    return b1 < b2;
  else
    return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void add(int x)
{
  if (++frq[x])cur++;
}

inline void remove(int x)
{
  if (--frq[x] == 0)cur--;
}

void mo()
{
  sort(qr + 1, qr + q + 1, comp);
  int l = 1, r = 0;
  cur = 0;
  for(int i=1;i<=q;i++)
  {
    while(l < qr[i].l) remove(a[l++]);
    while(l > qr[i].l) add(a[--l]);
    while(r < qr[i].r) add(a[++r]);
    while(r > qr[i].r) remove(a[r--]);
    ans[qr[i].idx] = cur;
  }
}

void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int id = 1;
  for (int i = 0; i < n; i++){
    if (i + k -1 < n)
    {
      qr[id].l = i;
      qr[id].r = i + k-1;
      qr[id].idx = id;
      id++;
    }
  }
  q = id;
  mo();
  for (int i = 1; i < )
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}