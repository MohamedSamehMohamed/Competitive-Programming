// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int x;
long long n;
vector<int> getPrimeFactors()
{
    vector<int> primeFactors;
    for(int i = 2; i <= x/i; i++)
    {
        if (x % i == 0)
        {
            primeFactors.push_back(i);
            while(x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x != 1)
        primeFactors.push_back(x);
    return primeFactors;
}
int fast(int b, long long p)
{
    int ret = 1;
    while(p)
    {
        if (p&1)
            ret = (1LL * ret * b) % mod;
        p >>= 1LL;
        b = (1LL * b * b) % mod;
    }
    return ret;
}
void solve()
{
    int ret = 1;
    for(int i: getPrimeFactors())
    {
        long long cur = i;
        while(cur <= n)
        {
            ret = (1LL * fast(i, n/cur) * ret) % mod;
            if (cur > n/i)break;
            cur *= i;
        }
    }
    printf("%d\n", ret);
}
int main()
{

    scanf("%d%lld", &x, &n);
    solve();
}
