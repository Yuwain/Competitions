#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string numSmall(int& q) {
  string N = to_string(q);
  
  if (N.size() == 1) {
    return N;
  }

  char non_zero_min = N.front();

  for (auto c : N) {
    if (c < non_zero_min && c != '0') {
      non_zero_min = c;
    }
  }

  auto el = N.begin();
  if (*el == non_zero_min) {
    ++el;
  } else {
    for (auto it = N.rbegin(); it != N.rend(); ++it) {
      if (*it == non_zero_min) {
        iter_swap(el, it);
        break;
      }
    }
    return N;
  }

  while (el != N.end()) {
    if (min_element(el, N.end()) == el) {
      ++el;
    } else {
      break;
    }
  }

  if (el == N.end()) {
    return N;
  }

  auto pos = N.rfind(*min_element(el, N.end()));
  char temp = *el;
  *el = N.at(pos);
  N.at(pos) = temp;

  return N;
}

string numBig(int& q) {
  string N = to_string(q);

  if (N.size() == 1) {
    return N;
  }

  auto el = N.begin();
  while (el != N.end()) {
    if (max_element(el, N.end()) == el) {
      ++el;
    } else {
      break;
    }
  }

  if (el == N.end()) {
    return N;
  }

  auto pos = N.rfind(*max_element(el, N.end()));
  char temp = *el;
  *el = N.at(pos);
  N.at(pos) = temp;

  return N;
}

int main() {
  int T, N;

  cin >> T;

  for (int i = 1; i <= T; ++i) {
    cin >> N;
    cout << "Case #" << i << ": " << numSmall(N) << " " << numBig(N) << endl;
  }

  return 0;
}
