#include <bits/stdc++.h>
using namespace std;
int n;
void test()
{
    scanf("%d", &n);
    queue<pair<string, int>> q;
    q.push({"1", 1 % n});
    while(!q.empty())
    {
        string ans = q.front().first;
        int cur = q.front().second;
        q.pop();
        if (cur % n == 0)
        {
            printf("%s\n", ans.c_str());
            break;
        }
        cur *= 10;
        q.push({ans + "0", cur % n});
        q.push({ans + "1", (cur+1)%n});
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}