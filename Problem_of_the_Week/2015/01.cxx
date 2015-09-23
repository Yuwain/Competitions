/* Problem: Given a list of users and integers, determine the two users with
            the most matching bits in their numbers and the two with the fewest
            matching bits in their numbers
   Example: A 2, B 3, C 4
            Most  - A B (one matching bit)
            Least - A C (no matching bits)                                     */
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
  Prints the names of the most matching pair and the least matching pair
  Input: users   - A list of users and their masks
         matches - A list of number of matching bit between any two users' masks
*/
void print_matches(vector<pair<string, unsigned int>>& users, vector<vector<int>>& matches) {
    int max = 0;
    int min = 32;
    
    tuple<int, int> min_xy(0, 0);
    tuple<int, int> max_xy(0, 0);
    
    for (auto i = 0u; i < users.size(); ++i) {
        for (auto j = i+1; j < users.size(); ++j) {
            if (matches[i][j] > max) {
                max = matches[i][j];
                get<0>(max_xy) = i;
                get<1>(max_xy) = j;
            }

            if (matches[i][j] < min) {
                min = matches[i][j];
                get<0>(min_xy) = i;
                get<1>(min_xy) = j;
            }
        }
    }
    
    cout << users[get<0>(max_xy)].first << " " << users[get<1>(max_xy)].first << endl;
    cout << users[get<0>(min_xy)].first << " " << users[get<1>(min_xy)].first << endl;
}

/*
  Returns the number of matching bits in two ints
  Input: i, j - two numbers to compare bits of
*/
int match(unsigned int i, unsigned int j) {
    unsigned int bits = ~(i ^ j);
    int count = 0;
    while (bits) {
        if (bits % 2) {
            ++count;
        }
        bits /= 2;
    }
    
    return count;
}

int main()
{
    int N;
    unsigned int mask;
    
    string name;
    
    vector<pair<string, unsigned int>> users;
    
    cin >> N;
    
    vector<vector<int>> compatiability;
    compatiability.resize(N);
    for (int i = 0; i < N; ++i) {
        compatiability[i].resize(N);
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> name >> mask;
        users.push_back(make_pair(name, mask));
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            compatiability[i][j] = match(users[i].second, users[j].second);
        }
    }
    
    print_matches(users, compatiability);
    
    return 0;
}
