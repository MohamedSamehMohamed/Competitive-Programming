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
class CopyingHomework
{
public :
vector<int> copy(vector<int> fh)
{
    fh[0]+=1;
    fh[1]-=2;
    fh[2]+=1;
    fh[3]+=1;
    fh[4]-=1;
    return fh ;
}
};
