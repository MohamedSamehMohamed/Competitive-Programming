// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
using namespace std ;
class  GreaterGameDiv2
{
public :
int calc(vector<int> snuke, vector<int> sothe)
{
    int ans =0 ;
    for (int i =0 ; i < SZ(snuke) ; i++)
    {
        ans += (snuke[i] > sothe[i]);
    }
    return ans ;
}
};
