// Author : Mohamed Sameh
// created in: 9:01 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int Q = 5e5 + 5;
const int M = 5e6 + 5;
const int SZ = sqrt(N) + 1;

struct data
{
  int l, r, idx;
}qr[Q];

int n, q, a[N];
int frq[M];
int ans[Q];
int total;
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
  if (++frq[x] == 1)total++;
}

inline void remove(int x)
{
  if (--frq[x] == 0)
    total--;
}

void mo()
{
  sort(qr + 1, qr + q + 1, comp);
  int l = 1, r = 0;
  total = 0;
  for(int i=1;i<=q;i++)
  {
    while(l < qr[i].l) remove(a[l++]);
    while(l > qr[i].l) add(a[--l]);
    while(r < qr[i].r) add(a[++r]);
    while(r > qr[i].r) remove(a[r--]);
    ans[qr[i].idx] = total;
  }
}

void test(){
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < q; i++){
    int l, r;
    scanf("%d%d", &l, &r);
    qr[i+1].l = l;
    qr[i+1].r = r;
    qr[i+1].idx = i;
  }
  mo();
  for (int i = 0; i < q; i++){
    printf("%d\n", ans[i]);
  }
}
int main()
{
  test();
}