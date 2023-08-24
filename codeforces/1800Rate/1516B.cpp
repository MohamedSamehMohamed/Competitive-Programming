// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
int a[N], n, prefix[N];
void test()
{
    scanf("%d", &n);
    prefix[n+1] = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    for(int i = 0; i < n; i++)
    {
        prefix[i+1] = prefix[i] ^ a[i];
    }
    bool can = prefix[n] == 0;
    for(int i = 0; !can && i < n; i++)
        for(int j = i+1; j < n; j++)
            can |= (prefix[i+1] == (prefix[j+1]^prefix[i+1]) && prefix[i+1] == (prefix[n] ^ prefix[j+1]));

    printf("%s\n", can? "YES": "NO");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();

}