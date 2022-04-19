/**
 * Author: AlirezaOpmc
 * 11 April
 */

#include <iostream>

using namespace std;

int sumVal(int x, int y) {
  x += y;
  return x;
}

int sumRef(int &x, int y) {
  x += y;
  return x;
}

int main() {
  int x = 3;
  int y = 4;

  int r1 = sumVal(x, y);

  cout << "x += y with value:\n";
  cout << "\tx:\t" << x << "\n";
  cout << "\ty:\t" << y << "\n";

  int r2 = sumRef(x, y);
  
  cout << "x += y with value:\n";
  cout << "\tx:\t" << x << "\n";
  cout << "\ty:\t" << y << "\n";
}
