/* Problem: Find the nth prime number */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  bool flag;
  int num = 1;
  unsigned int n;
  vector<long> primes = {2};

  cout << "Input nth prime to find: ";
  cin >> n;

  while (primes.size() < n) {
    flag = true;
    num += 2; 

    for (int i = 0; primes.at(i) <= sqrt(num); ++i) {
      if ((num % primes.at(i)) == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      primes.push_back(num);
    }
  }

  cout << primes.size() << "th prime is " << primes.at(primes.size()-1) << endl;

  return 0;
}
