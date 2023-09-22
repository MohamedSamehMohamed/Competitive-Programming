#include <bits/stdc++.h>
#include <unistd.h>
//#include "testlib-master/testlib.h"
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long upper) {
  return rng() % upper;
}
int n, a, b;
string str;
void generateInput(){
  ofstream cout("input");
  n = 1 + myRand(100);
  cout << 1 <<"\n";
  cout << n << "\n";
  for (int i = 0; i < n; i++){
    a = myRand(n);
    cout << a;
    if (i + 1 < n) cout <<" ";
    else
      cout << "\n";
  }
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
  while(cnt < 10000){
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
