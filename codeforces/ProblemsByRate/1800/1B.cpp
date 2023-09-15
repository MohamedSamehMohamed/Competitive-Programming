#include <bits/stdc++.h>
using namespace std;
char x[30];
string getRow(string row)
{
  int rowNumber = 0;
  reverse(row.begin(), row.end());
  for (int i = 0, val = 1; i < row.size(); i++, val *= 26)
  {
    rowNumber += val * (row[i] - 'A' + 1);
  }
  return to_string(rowNumber);
}
string getRowString(int row)
{
  int steps = 0;
  int cur = 1;
  while(row > 0)
  {
    cur *= 26;
    steps++;
    row -= cur;
  }
  row += cur - 1;
  string rowString("", steps);
  for (int i = steps - 1; i >= 0; i--)
  {
    rowString[i] = 'A' + row % 26;
    row /= 26;
  }
  return rowString;
}
string toMethodOne(string input)
{
  string row = "";
  int i, col = 0;
  for (i = 0; input[i] >= 'A' && input[i] <= 'Z'; i++) row += input[i];
  for (;i < input.size(); i++) col = col * 10 + (input[i] - '0');
  return "R" + getRow(row) + "C" + to_string(col);
}
string toMethodTwo(string input)
{
  int row = 0, col = 0;
  for (int i = 1; i < input.size(); i++)
  {
    if (input[i] == 'C')
    {
      swap(row, col);
      continue;
    }
    row = row * 10 + (input[i] - '0');
  }
  swap(row, col);
  return getRowString(row) + to_string(col);
}
bool isMethodOne(string input)
{
  // R[number]C[number]
  bool flag = 0;
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] >= '0' && input[i] <= '9') continue;
    while(i < input.size() && input[i] >= 'A' && input[i] <= 'Z')
      i++;
    flag |= (i < input.size() && (input[i] >= '0' && input[i] <= '9'));
  }
  return flag;
}
void test()
{
  scanf(" %s", x);
  string cur = x;
  cur = (isMethodOne(cur)? toMethodTwo(cur): toMethodOne(cur));
  printf("%s\n", cur.c_str());
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
}
