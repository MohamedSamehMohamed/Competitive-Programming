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
int t ;
string x ;
string ops = "+-*/^";
bool CanAdd (char a , char b)
{
    int i = 0 , j  = 0 ;
    while (ops[i] != a)i++;
    while (ops[j] != b)j++;
    return j > i ;
}
int main()
{
    cin >> t ;
    while (t--)
    {
        stack<char> st ;
        cin >> x ;
        for (int i =0;i < SZ(x) ; i++)
        {
            if (x[i] == '(')
            {
                st.push(x[i]);
                continue ;
            }else if (x[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
                continue ;
            }
            if (x[i] >= 'a' && x[i] <= 'z')
            {
                cout << x[i];
            }else
            {
                if (st.empty() || st.top() == '(' || CanAdd(st.top()  , x[i]))
                {
                  st.push(x[i]);
                }else{
                  while(!st.empty() && st.top() != '(' && !CanAdd(st.top() , x[i]))
                  {
                      cout << st.top() ;
                      st.pop();
                  }
                  st.push(x[i]);
                }
            }
        }
        while (!st.empty())
        {
            cout << st.top() ;
            st.pop();
        }
        cout << '\n';
    }
}
