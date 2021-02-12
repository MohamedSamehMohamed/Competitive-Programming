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
int n ;
int a[1000][2];
bool IsStack ()
{
    stack<int> st ;
    for (int i =0 ; i < n ;i++)
    {
        if (a[i][0] == 1 )
        {
            st.push(a[i][1]);
        }else
        {
            if (st.empty())return 0;
            if (st.top() != a[i][1])return 0;
            st.pop();
        }
    }
    return 1 ;
}
bool IsQueue ()
{
    queue<int> q ;
    for (int i =0 ; i < n ;i++)
    {
        if (a[i][0] == 1 )
        {
            q.push(a[i][1]);
        }else
        {
            if (q.empty())return 0;
            if (q.front() != a[i][1])return 0;
            q.pop();
        }
    }
    return 1 ;
}
bool IsPq ()
{
    priority_queue<int> pq ;
    for (int i =0 ; i < n ;i++)
    {
        if (a[i][0] == 1 )
        {
            pq.push(a[i][1]);
        }else
        {
            if (pq.empty())return 0;
            if (pq.top() != a[i][1])return 0;
            pq.pop();
        }
    }
    return 1 ;
}
int main()
{
    while (scanf("%d" , &n) == 1 )
    {
        for (int i =0 ; i < n ;i++)
        {
            scanf ("%d%d" , a[i] , a[i]+1 );
        }
        bool Stack = IsStack();
        bool Queue = IsQueue();
        bool PQ    = IsPq();
        int sum = Stack + Queue + PQ ;
        if (sum < 1)
        {
            printf ("impossible\n");
        }else if (sum == 1 )
        {
            if (Stack)
            {
                printf ("stack\n");
            }else if (Queue)
            {
                printf ("queue\n");
            }else
            {
                printf ("priority queue\n");
            }
        }else
        {
            printf ("not sure\n");
        }
    }

}
