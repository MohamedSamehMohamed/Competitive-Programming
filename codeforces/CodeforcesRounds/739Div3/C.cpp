// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int k;
void test()
{
    scanf("%d", &k);
    long long mn = sqrt(k);
    mn = max(mn, 1LL);
    while (1LL * mn * mn < k)
        mn++;
    long long before = 1LL * (mn-1) * (mn-1);
    long long left = k - before;
    int row = mn;
    int col = mn;
    if (left > mn)
    {
        col = mn - (left - mn);
    }else
    {
        row = mn - (mn - left);
    }
    printf("%d %d\n", row, col);
}
int main()
{

    int t;
    scanf("%d", &t);
    while(t--)
        test();
}