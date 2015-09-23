#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

double time_to_win() {
  double time = 0,
         time_win,
         farm_cost,
         time_farm,
         farm_speed,
         time_win_next,
         win_condition,
         cookies_per_second = 2;

  cin >> farm_cost >> farm_speed >> win_condition;

  while (true) {
    if (farm_cost > win_condition) {
      return (win_condition / cookies_per_second);
    } else {
      time_win = (win_condition / cookies_per_second);
      time_farm = (farm_cost / cookies_per_second);
      time_win_next = (win_condition / (cookies_per_second + farm_speed));

      if (time_win > (time_farm + time_win_next)) {
        time += time_farm;
        cookies_per_second += farm_speed;
      } else {
        time += time_win;
        return time;
      }
    }
  }
}

int main() {
  int T;

  cout << fixed << setprecision(7);

  cin >> T;

  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": " << time_to_win() << endl;
  }

  return 0;
}
