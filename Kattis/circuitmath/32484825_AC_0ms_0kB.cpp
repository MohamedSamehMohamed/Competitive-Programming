// Author: Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int n;
int val[26];
vector<char> expression;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char c;cin >> c;
        val[i] = (c == 'T');
    }
    char x;
    while(cin >> x)
        expression.push_back(x);
    stack<int> stk;
    for(int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c >= 'A' && c <= 'Z')
        {
            stk.push(val[c-'A']);
        }else
        {
            int cur = stk.top();
            stk.pop();
            if (c == '-')
            {
                stk.push(!cur);
            }else
            {
                int b = stk.top();
                stk.pop();
                stk.push(c == '*'? cur & b: cur | b);
            }
        }
    }
    printf("%c\n", stk.top()? 'T': 'F');
}