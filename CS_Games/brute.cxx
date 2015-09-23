#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
 // fstream in(argv[1]);
  fstream data(argv[0]);
 // fstream out(argv[2]);
  string dat, input, things;
  int i = 0;
  while (getline(data, things))
  {
    dat += things;
  }
  data.close();
  fstream in(argv[1]);
  string output;
  cout << dat << ";";
  vector<string> a;
  while (getline(in, input))
  {
    a.push_back(input);
  }
  in.close();
    int count = 0;
     while ((i = dat.find(input, i)) != string::npos)
     {
         ++i;
         ++count;
         cout << "count = " << count << " " << input << endl;
     } 
     
  
  fstream out(argv[2]);
  out.close();
  return 0;
}
