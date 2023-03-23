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
class GravityPuzzleEasy
{
public :
vector<string> solve(vector<string> board)
{
    int r = board.size();
    int c = board[0].size();

    for (int i = r-1; i >=0 ; i--)
    {
        for (int j = 0 ; j < c ; j++)
        {
            if (board[i][j] == '.')continue ;
            int k = i+1 ;
            while (k < r && board[k][j] == '.')
            {
                swap(board[k-1][j] , board[k][j]);
                k++;
            }
        }
    }
    return board;

}
};
