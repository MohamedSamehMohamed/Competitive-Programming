#include <bits/stdc++.h>
using namespace std;
/*
 * if n is odd
 * then for any x such that x|n, x is also odd
 * (n - x) is even and x | (n-x)
 * and not power of 2, because x is odd
 * even and not power of 2 then it has at least one odd divisor
 *
 * odd -> even -> odd -> even -> odd -> even -> ... -> (prime or 1)
 * start with odd number you can't win,
 *
 * if n is even and not power of 2
 * you can win like first case
 *
 * if n is power of 2
 * there is no odd divisor so you can't make n odd
 * and you can't subtract any number except n/2
 * because n won't be power of two
 *
 *
 * 1 lose
 * 2 lose
 * 4 win
 * 8 -> 4 -> 2 lose
 *
 *
 */
int n;
void test()
{
    scanf("%d", &n);
    if ((n % 2) || n <= 2)
    {
        printf("Bob\n");
        return;
    }
    if (n & (n-1))
    {
        printf("Alice\n");
    }else
    {
        int p = 0;
        while(n)
        {
            n >>= 1;
            p ^= 1;
        }
        printf("%s\n", (p? "Bob": "Alice"));
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}