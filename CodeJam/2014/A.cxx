#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int T,
      ans,
      count,
      result;

  int array[4][4];

  vector<int> check;

  cin >> T;

  for (int i = 0; i < T; ++i) {
    count = 0;
    result = 0;
    check.clear();

    cin >> ans;

    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        cin >> array[j][k];
      }
    }

    for (int j = 0; j < 4; ++j) {
      check.push_back(array[ans-1][j]);
    }

    cin >> ans;

    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        cin >> array[j][k];
      }
    }

    for (int j = 0; j < 4; ++j) {
      for (auto elem : check) {
        if (array[ans-1][j] == elem) {
          ++count;
          result = elem;
        }
      }
    }

    if (count == 1) {
      cout << "Case #" << i+1 << ": " << result << endl;
    } else if (count < 1) {
      cout << "Case #" << i+1 << ": " << "Volunteer cheated!" << endl;
    } else {
      cout << "Case #" << i+1 << ": " << "Bad magician!" << endl;
    }
  }

  return 0;
}
