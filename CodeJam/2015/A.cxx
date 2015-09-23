#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
  unsigned short T, Smax;
  unsigned int total, count;
  vector<int> shyness;
  string Si;

  cin >> T;

  for (auto i = 1; i <= T; ++i) {
    total = 0;
    count = 0;
    shyness.clear();
    cin >> Smax >> Si;
    for (auto&& it : Si) {
      shyness.push_back(it - '0');
    }

    for (auto j = 0u; j < shyness.size()-1; ++j) {
      total += shyness[j];
      while (total <= j) {
        count++;
        total++;
      }
    }
    cout << "Case #" << i << ": " << count << endl;
  }

  return 0;
}
