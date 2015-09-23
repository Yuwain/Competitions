/* Problem: Given a list of friendships, list each person alphabetically
            along with their respective degrees of separation to Quinn
            or 'uncool' if they aren't connected to Quinn.
   Example: A Quinn, B A, C D
            A - 1
            B - 2
            C - uncool
            D - uncool
            Quinn - 0                                                    */
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
  private:
    int dist_;
    string name_;
    vector<Node*> buds;

  public:
    Node(string name) : dist_(-1), name_(name) {}

    void add(Node& person) {
      buds.push_back(&person);
    }

    void set_dist(int num) {
      dist_ = num;
    }
    
    int get_dist() {
      return dist_;
    }

   string get_name() {
      return name_;
    }

    vector<Node*> get_buds() {
      return buds;
    }

    friend ostream& operator<<(ostream& os, const map<string, Node>& p) {
      for (auto elem : p) {
        int dist = elem.second.get_dist();
        os << elem.first << " " 
           << (dist == -1 ? "uncool" : to_string(dist)) << endl;
      }
      return os;
    }
};

/* 
 * Finds the QDist, the degree of separation to Quinn, for everyone connected
 * to Quinn in some way. Those without ties to Quinn are left with -1 QDist. 
 */
void find_dist(map<string, Node>& people) {
  Node* root = &people.at("Quinn");
  root->set_dist(0);

  queue<Node*> bfs;
  bfs.push(root);

  while (!bfs.empty()) {
    Node* curr = bfs.front();
    bfs.pop();


    for (auto guy : curr->get_buds()) {
      if (guy->get_dist() == -1) {
        guy->set_dist(curr->get_dist()+1);
        bfs.push(guy);
      }
    }
  }
}

int main() {
  int n;
  string person1, person2;
  map<string, Node> people;

  cin >> n;

  //Just in case Quinn has no friends :c
  people.insert(pair<string, Node>("Quinn", Node("Quinn")));   
  
  for (int i = 0; i < n; ++i) {
    cin >> person1 >> person2;
    people.insert(pair<string, Node>(person1, Node(person1)));
    people.insert(pair<string, Node>(person2, Node(person2)));

    people.at(person1).add(people.at(person2));
    people.at(person2).add(people.at(person1));
  }

  find_dist(people);

  cout << people;

  return 0;
}
