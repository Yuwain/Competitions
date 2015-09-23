#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<float> weigh_blocks(int N) {
  float block;
  vector<float> blocks; 

  for (int k = 0; k < N; ++k) {
    cin >> block;
    blocks.push_back(block);
  }

  return blocks;
}

int deceitful_war(vector<float> naomi, vector<float> ken) {
  int points = 0;
  
  while (naomi.size() > 0) {
    if (naomi.back() < ken.front()) {
      return points;
    } else if (naomi.front() < ken.front()) {
      ken.pop_back();
      naomi.erase(naomi.begin());
    } else {
      ken.erase(ken.begin());
      naomi.erase(naomi.begin());
      ++points;
    }
  }
  
  return points; 
}

int war(vector<float> naomi, vector<float> ken) {
  int points = 0;
  
  while (naomi.size() > 0) {
    if (naomi.back() < ken.front()) {
      return points;
    } else if (naomi.back() > ken.back()) {
      naomi.pop_back();
      ken.erase(ken.begin());
      ++points;
    } else {
      ken.erase(upper_bound(ken.begin(), ken.end(), naomi.back()));
      naomi.pop_back();
    }
  }
  
  return points;
}

int main() {
  int N,
      T,
      x,
      y;

  vector<float> naomi, 
                ken;

  cin >> T;

  for (int i = 0; i < T; ++i) {
    naomi.clear();
    ken.clear();


    cin >> N;

    naomi = weigh_blocks(N);
    ken = weigh_blocks(N);

    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());

    x = deceitful_war(naomi, ken);
    y = war(naomi, ken);

    cout << "Case #" << i+1 << ": " << x << " " << y <<  endl;

  }

  return 0;
}
