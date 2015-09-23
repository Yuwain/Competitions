/* Problem:  Find the last 10 digits of 28433 * 2e7830457 + 1 */
#include <iostream>

using std::cout;
using std::endl;

int main() {
  long y = 1;

  for (long x = 1; x <= 7830457; ++x) {
    y = (y * 2) % 10000000000;
  }
  y = ((y*28433)+1)%10000000000;

  cout << "y = " << y << endl;

  return 0;
}
