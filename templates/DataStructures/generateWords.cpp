#include<bits/stdc++.h>
using namespace std;
#define UID uniform_int_distribution<int>
mt19937 eng{random_device{}()};
const int SIZE = 25;
bool grid[SIZE][SIZE];
void paint(int r, int c, int color)
{
	if (r >= SIZE || c >= SIZE || r < 0 || c < 0) 
		return;
	grid[r][c] = color;
}
void paint(int r, int c, int h, int w)
{
	for (int i = r; i < r + w; i++)
		for (int j = c; j < c + h; j++)
			paint(i, j, 1);
}
void reverse(int r, int c, int h, int w)
{
	for (int i = r; i < r + w; i++)
		for (int j = c; j < c + h; j++)
		{
			if (i >= SIZE || j >= SIZE || i < 0 || j < 0)
				continue;
			paint(i, j, !grid[i][j]);
		}
}
int main()
{
	memset(grid, 0, sizeof grid);
	UID rnd(0, SIZE);
	int rep = 10 + rnd(eng);
	for (int i = 0; i < rep; i++)
	{
		int row = rnd(eng);
		int col = rnd(eng);
		int w = rnd(eng);
		int h = rnd(eng);
		if (rnd(eng) % 2)
			paint(row, col, h, w);
		else 
			reverse(row, col, h, w);
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << (grid[i][j]? "*": "#") <<" \n"[j + 1 == SIZE];
	}
}
 