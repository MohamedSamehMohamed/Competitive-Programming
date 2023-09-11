// Author : Mohamed Sameh
// created in: 9:13 AM
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
class MInt{
  int value = 0;
  public:
    MInt(int value){
      this->value = value;
    }
    int operator*(int other){
      return (value * other)%mod;
    }
    int operator*=(int other){
      value = (1LL * value * other) % mod;
      return value;
    }
    bool operator==(int other){
      return value == other;
    }
    bool operator==(MInt other){
      return value == other.getValue();
    }
    int getValue() const{
      return value;
    }
};
ostream& operator<<(ostream& stream, const MInt& number) {
  return stream << number.getValue();
}
int main()
{
  MInt n(1);
  int m = 2;
  n = 4;
  cout << n <<"\n";
  if (n == m)
    cout << n << "\n";
}