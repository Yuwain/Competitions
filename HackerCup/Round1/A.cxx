#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int primacity(int A, int B, int K, vector<int>& primes) {
  set<int> divisors;
  int count = 0;
  bool done;
  int a = A;
  for (; a <= B; a++) {
    divisors.clear();
    A = a;
    done = false;

    //Add all primes that divide A to a set
    //Since it's a set, duplicates can't exist
    while (!done) {
      done = true;
      for (auto prime : primes) {
        if (A % prime == 0) {
          A = A/prime;
          divisors.insert(prime);
          done = false;
          break;
        }
      }
    }

    int m = divisors.size();
    if (m == 0) {
      m = 1;
    }
    if (m == K) {
      ++count;
    }
  }

  return count;
}

int main() {
  int T, A, B, K;
  vector<int> primes = {2, 3};

  cin >> T;

  for (int i = 1; i <= T; ++i) {
    cin >> A >> B >> K;

    for (int j = (primes.back() + 2); j <= floor(sqrt(10000000)); j = j+2) {
      bool isPrime = true;
      for (int prime : primes) {
        if ((j % prime) == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        primes.push_back(j);
      }
    }
    cout << "Case #" << i << ": " << primacity(A, B, K, primes) << endl;
  }
  return 0;
}
