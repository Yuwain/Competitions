#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cmath>

using namespace std;

int main() {
  int T, D, Pi, expected, temp, timestep;
  vector<int> pancakes, next;

  cin >> T;

  for (auto i = 1; i <= T; ++i) {
    expected = 0;
    timestep = 0;
    pancakes.clear();

    cin >> D;
    for (auto j = 0; j < D; ++j) {
      cin >> Pi;
      pancakes.push_back(Pi);
    }
    sort(pancakes.begin(), pancakes.end());
    expected = pancakes.back();

    while (pancakes.size() > 0) {
      temp = pancakes.back();
      pancakes.pop_back();
      if (temp != 1) {
      pancakes.push_back(floor(temp/float(2)));
      pancakes.push_back(ceil(temp/float(2)));
      }
      sort(pancakes.begin(), pancakes.end());
      temp = pancakes.back();

      timestep++;
      if (expected > temp + timestep) {
        expected = temp + timestep;
      }
    }

    cout << "Case #" << i << ": " << expected << endl;
  }

  return 0;
}
