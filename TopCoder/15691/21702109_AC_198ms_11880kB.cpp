// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
class MilkConsumption
{
public :
vector<int> findMaxRegion(vector<int> p , vector<int> t)
{
    int best = 0 ;
    for (int i =1 ; i < SZ(p) ;i++)
    {
        if (1.0*t[i] / p[i] > 1.0*t[best] / p[best])best = i;
    }
    return {best};
}

};

