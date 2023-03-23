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
class SixteenQueens
{
int board[51][51];
vector<int> W ;
int N ;
bool check (int r , int c )
{
for (int i =0 ; i < N ;i++)
{
    bool ok = 0 ;
    for (int j =0 ; j < N ; j++)
    {
        if (board[i][j] && ok )return false ;
        if (board[i][j])ok=1;
    }
}
for (int i =0 ; i < N ;i++)
{
    bool ok =0 ;
    for (int j =0 ; j < N ; j++)
    {
        if (board[j][i] && ok )return false ;
        if (board[j][i])ok = 1;
    }
}
for (int i = r-1 , j = c-1 ; i >= 0 && j >= 0 ; i--,j--)if (board[i][j])return false ;
for (int i = r+1 , j = c-1;  i < N && j >= 0 ; i++,j--)if (board[i][j])return false ;
for (int i = r-1,  j = c+1 ; i >=  0 && j < N ; j++,i--)if (board[i][j])return false  ;
for (int i = r+1 , j = c+1 ; i < N && j < N ; i++,j++)if (board[i][j])return false ;
return true ;
}

bool rec (int c , int rm )
{
    if (rm == 0 )return 1 ;
    for (int i =0 ; i < N ; i++ )
    {
        if (board[i][c] == 0 )
        {
            board[i][c] = 2 ;
            if (check(i , c ) && rec(c + 1 , rm - 1))return 1 ;
            board[i][c] = 0;
        }
    }
    return rec (c+1 , rm );
}
public :
    vector<int> addQueens(vector<int> row, vector<int> col, int add)
    {
        N = 51 ;
        vector<int> ans ;
        memset(board , 0 , sizeof board );
        for (int i =0 ; i < SZ(row) ; i++)
        {
            board[ row[i] ][  col[i] ] = 1 ;
        }
        rec(0 , add );
        for (int i =0 ; i < N ;i++)
            for (int j =0 ; j < N ; j++)
        {
            if (board[i][j] == 2 )
            {
                ans.pb(i);
                ans.pb(j);
            }
        }
        return ans ;
    }
};
