// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
vector<int> C;
int n, c; 
long long dp[60][260];
long long solve(int i, int rm)
{
    if (rm < 0)return 0;
    if (rm == 0)return 1;
    if (i == C.size())return 0; 
    long long &ret = dp[i][rm];
    if (~ret)return ret; 
    ret = solve(i+1, rm);
    ret = ret + solve(i, rm - C[i]);  
    return ret; 
}
int main()
{
 cin >> c >> n;
 C = vector<int>(n);
 for (auto &i: C)cin >> i; 
 memset(dp, -1, sizeof dp); 
 cout << solve(0, c) << "\n"; 
}
