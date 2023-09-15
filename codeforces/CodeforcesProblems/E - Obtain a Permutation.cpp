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
int ans, n, m;
int main()
{
    ios::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
    cin >> n >> m ;
    vector<int> v[n];
    for (int i =0 ; i < n ;i++)
    {
        v[i] = vector<int> (m);
        for (int j =0 ; j < m ;j++)
        {
            cin >> v[i][j]; 
        }
    }
    for (int i =0 ; i < m ;i++)
    {
        set<int> st  ;
        map<int,int>mp;
        for (int j =0 ; j < n ;j++)
        {
            st.insert(j * m + i + 1 );
        }
        for (int j =0 ; j < n ;j++)
        {
            if (st.count(v[j][i]))
            {
                v[j][i]-=(i+1); 
                v[j][i]/=m; 
                if (j >= v[j][i])
                {
                    mp[ j - v[j][i] ]++; 
                }else 
                {
                    mp[ n - (v[j][i] - j) ]++; 
                }
            }
        }
        if (mp.empty())
        {
            ans += n;
            continue ;
        }
        int mnop = n ;
        for (auto it : mp)
        {
            mnop = min (mnop , it.f + (n - it.s ));
        }
        ans += mnop ; 
    }
    cout << ans <<"\n"; 
    
}
