#include <algorithm>

int find_singular(std::vector<int>& array) {
  return std::accumulate(array.begin(), array.end(), 0x0, std::bit_xor<int>());
}
