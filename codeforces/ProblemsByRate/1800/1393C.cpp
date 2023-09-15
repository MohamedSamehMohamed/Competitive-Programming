#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int frq[N], n;
vector<int> numbers;
bool can(int d)
{
    for(int i = 0; i < d; i++)
    {
        int sp = n / d + (i < n % d);
        if (sp < numbers[i])return 0;
    }
    return  1;
}
void test()
{
    scanf("%d", &n);
    memset(frq, 0, 4 * (n+1));
    numbers.clear();
    for(int i = 0; i < n; i++)
    {
        int x;scanf("%d", &x);
        frq[x]++;
    }
    for(int i = 0; i <= n; i++)if(frq[i])numbers.push_back(frq[i]);
    sort(numbers.rbegin(), numbers.rend());
    int l = 0, r = numbers.size()-1, m, ans = 0;
    while(l <= r)
    {
        m = (l+r) >> 1;
        if (can(m+1))
            ans = m, l = m+1;
        else
            r = m-1;
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}