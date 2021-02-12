// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
    string x ;
    while (cin >> x )
    {
        deque<char> dq ;
        int n = SZ(x);
        bool en = 1 ;
        stack<char> home ;
        for (int i =0 ; i < n ;i++)
        {
            if (x[i] == ']')
            {
                en =1 ;
            }else if (x[i] == '[')
            {
                while(!home.empty())
                {
                    dq.push_front(home.top()); home.pop();
                }
                en = 0;

            }else
            {
                if (en)
                {
                    dq.push_back(x[i]);
                }else
                {
                    home.push(x[i]);
                }
            }
        }
        while(!home.empty())
        {
            dq.push_front(home.top()); home.pop();
        }
        while(!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
        }
        printf ("\n");
    }

}
