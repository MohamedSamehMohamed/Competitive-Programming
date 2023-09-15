// Author : Mohamed Sameh
// created in: 1:31 PM
#include <bits/stdc++.h>
using namespace std;
int n, k;
int mod = 998244353;
char boardconfig[290];
void test(){

  int i;
  for(i=0;i<289;i++)
    boardconfig[i]='0';

  //red
  boardconfig[4]='r';
  boardconfig[21]='r';
  boardconfig[22]='r';
  boardconfig[38]='r';
  boardconfig[39]='r';
  boardconfig[40]='r';
  boardconfig[55]='r';
  boardconfig[56]='r';
  boardconfig[57]='r';
  boardconfig[58]='r';

  //green
  boardconfig[77]='g';
  boardconfig[78]='g';
  boardconfig[79]='g';
  boardconfig[80]='g';
  boardconfig[95]='g';
  boardconfig[96]='g';
  boardconfig[97]='g';
  boardconfig[113]='g';
  boardconfig[114]='g';
  boardconfig[131]='g';

  //purple
  boardconfig[166]='p';
  boardconfig[183]='p';
  boardconfig[184]='p';
  boardconfig[200]='p';
  boardconfig[201]='p';
  boardconfig[202]='p';
  boardconfig[217]='p';
  boardconfig[218]='p';
  boardconfig[219]='p';
  boardconfig[220]='p';

  //orange
  boardconfig[230]='o';
  boardconfig[231]='o';
  boardconfig[232]='o';
  boardconfig[233]='o';
  boardconfig[248]='o';
  boardconfig[249]='o';
  boardconfig[250]='o';
  boardconfig[266]='o';
  boardconfig[267]='o';
  boardconfig[284]='o';

  //blue
  boardconfig[157]='b';
  boardconfig[174]='b';
  boardconfig[175]='b';
  boardconfig[191]='b';
  boardconfig[192]='b';
  boardconfig[193]='b';
  boardconfig[208]='b';
  boardconfig[209]='b';
  boardconfig[210]='b';
  boardconfig[211]='b';

  //yellow
  boardconfig[68]='y';
  boardconfig[69]='y';
  boardconfig[70]='y';
  boardconfig[71]='y';
  boardconfig[86]='y';
  boardconfig[87]='y';
  boardconfig[88]='y';
  boardconfig[104]='y';
  boardconfig[105]='y';
  boardconfig[122]='y';

  // now the black part ( center part )

  for(i=68;i<=80;i++)
    boardconfig[i]='c';
  for(i=86;i<=97;i++)
    boardconfig[i]='c';
  for(i=104;i<=114;i++)
    boardconfig[i]='c';
  for(i=122;i<=131;i++)
    boardconfig[i]='c';
  for(i=157;i<=166;i++)
    boardconfig[i]='c';
  for(i=174;i<=184;i++)
    boardconfig[i]='c';
  for(i=191;i<=202;i++)
    boardconfig[i]='c';
  for(i=208;i<=220;i++)
    boardconfig[i]='c';
  for(i=140;i<=148;i++)
    boardconfig[i]='c';
  i = 0;
  while (i < 289){
    for (int j = 0; j < 17; j++)
      cout << boardconfig[i++] <<" ";
    cout <<"\n";
  }
}
int main()
{
  test();
}