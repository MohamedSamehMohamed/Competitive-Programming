// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int k;
bool good(int x)
{
    if (x % 3 == 0)return 0;
    if (x % 10 == 3)return 0;
    return 1;
}
void test()
{
    scanf("%d", &k);
    for(int i = 1; ; i++)
    {
        if (good(i))
        {
            k--;
            if (k == 0)
            {
                printf("%d\n", i);
                return;
            }
        }
    }

}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}