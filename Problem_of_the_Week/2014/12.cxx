#include <vector>
#include <iostream>
#include <unordered_set>

#include <cassert>

using namespace std;

int countNumberWithDifference(vector<int> list, int value) {
  int count = 0;

  unordered_multiset<int> set;

  for (int& item : list) {
    set.insert(item + value);
  }

  for (int& item : list) {
      count += set.count(item);
  }

  return count;
}

int main() {
  const vector<int> ANS = {2, 4, 4};
  const vector<vector<int>> VEC = {{0, 1, 3, 5, 6, 9}, 
                                   {0, 1, 1, 2, 3, 5}, 
                                   {3, 1, 4, 1, 3, 9}};

  /* ARE YOU HAPPY NOW, STEPHEN */
  assert(ANS.size() == VEC.size());

  /* ARE YOU */
  for (unsigned int i = 0; i < ANS.size(); ++i) {
    assert(countNumberWithDifference(VEC.at(i), 2) == ANS.at(i));
  }

  return 0;
}
