#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a, b, k;
int P[N], idx;
bool siev[N];
map<int, int> A, B;
void Siev()
{
    for(int i = 2; i <= N/i; i++)
    {
        if (siev[i])continue;
        for(int j = i * i; j < N; j+=i)
            siev[j] = 1;
    }
    for(int i = 2; i < N; i++)
        if (!siev[i])P[idx++] = i;
}
map<int, int> factorize(int number)
{
    map<int, int> ret;
    for(int i = 0; i < idx && P[i] <= number/P[i]; i++)
    {
        while (number % P[i] == 0)
        {
            ret[P[i]]++;
            number /= P[i];
        }
    }
    if (number != 1)ret[number]++;
    return  ret;
}
bool can(int tar)
{
   auto ret = factorize(tar);
   int need = 0;
   for(auto i: A)
       need += max(0, i.second - ret[i.first]);
   for(auto i: B)
        need += max(0, i.second - ret[i.first]);
   int mn = 2;
   if (a == tar)mn--;
   if (b == tar)mn--;
   return k >= mn && k <= need;
}
void test()
{
    scanf("%d%d%d", &a, &b, &k);
    if (k > 2 * 30)
    {
        printf("No\n");
        return;
    }
    A = factorize(a);
    B = factorize(b);
    int g = __gcd(a, b);
    bool ok = 0;
    for(int i = 1; !ok && i <= g/i; i++)
    {
        if (g % i == 0)
        {
            ok |= can(i);
            ok |= can(g/i);
        }
    }
    printf("%s\n", ok? "Yes": "No");
}
int main()
{
    Siev();
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}