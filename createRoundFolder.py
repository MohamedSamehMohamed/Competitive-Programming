# This is a simple script that creates a folder with given name, and number of files all with the given template 
# example on windows: python.exe .\createRoundFolder.py 752-Div2 6
# create a folder with name [752-Div2] and inside the folder creates 6 files with the same text as in template variable 

import sys 
import os 

def get_Path(file_name):
    Path = os.path.dirname(os.path.abspath(__file__))
    my_file = os.path.join(Path, file_name)
    return my_file
  
template = '''#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
void test()
{

}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
'''
folder_name = sys.argv[1]
file_cnt = int(sys.argv[2])
os.mkdir(get_Path(folder_name))
for i in range(file_cnt):
    file_name = chr(ord('A') + i)
    file = open(get_Path(folder_name + '/' + file_name + '.cpp'), 'a')
    file.writelines(template)
    file.close()
f = open(get_Path(folder_name + '/' + 'in' + '.txt'), 'a')
f.close()
