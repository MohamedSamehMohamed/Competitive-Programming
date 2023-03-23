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
class  ThreePartSplit
{
public :
vector <int> split(int a, int d)
{
    int rang = (d - a)/3 ;
    return {a + rang , a + 2 * rang };
}
};
