#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
// Start Of compiling and running wrong and accepted Code
const string dirPath = "F:\\ProgrammingLangueTraining\\c++\\Competitive-Programming\\StressTest\\";
// c++ file
void compileFile(string fileName){
  string compileCommand = "g++ " + fileName + ".cpp -std=c++11 -o " +
                          fileName + ".out -O3";
  system(compileCommand.c_str());
}
void runFile(string fileName){
  string runCommand = fileName + ".out " + "< input > " + fileName;
  system(runCommand.c_str());
}
// End Of compiling and running wrong and accepted Code

void generateInput(){
  ofstream cout("input");
  int n = 1 + rand();
  int m = 2 + rand();
  cout << n << ' ' << m << '\n';
  cout.close();
}
bool compareOutput(string ac, string wa){
  return ac == wa;
}
int main(){
  chdir(dirPath.c_str());
  compileFile("ac");
  compileFile("wa");
  int cnt = 0;
  while(1){
    cnt++;
    generateInput();
    runFile("ac");
    runFile("wa");
    ifstream was("wa");
    ifstream acs("ac");
    string wa, ac;
    getline(was, wa,(char) EOF);
    getline(acs, ac,(char) EOF);
    if (compareOutput(ac, wa) == 0){
      cout << "failed\n";
      break;
    }else {
      cout << cnt << " tests passed\n";
    }
  }
}
