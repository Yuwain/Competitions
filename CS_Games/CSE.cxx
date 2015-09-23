#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
using namespace std;
map<char, int> build(fstream& in, std::string pat)
{
  char lastChar;
  int curr = 1, size = pat.size();
  bool foundlast = false;
  map<char, int> array;
  string::reverse_iterator i = pat.rbegin();
  lastChar = *i;

  for (++i; i != pat.rend(); ++i)
  {
    cout << *i << endl;
    if (array.find(*i) == array.end())
    {
      array[*i] = curr;
    }
    if (*i == lastChar)
      foundlast = true;
    ++curr;
  }
  cout << "what";
  if (!foundlast)
  {
    string::reverse_iterator l = pat.rbegin();
    cout << *l << endl;
    array[*l] = size;
  }
  return array;
}

int search(map<char, int> array, string in, string pat)
{
  int size = pat.size();
  string::iterator start = in.begin();
  string::iterator end = start + size - 1;
  string::iterator temp;
  int count = 0;
  while (end < in.end()) {
    string::iterator starttemp = start;
    temp = end;
    size = pat.size() - 1;

    for (int i = array.size(); i > 0; --i)
    {
      if (*temp != pat.at(size))
      {
        map<char, int>::iterator move = array.find(pat.at(size));
        if (move == array.end())
        {
          advance(start, array.size());
          advance(end, array.size());
        }
        else
        {
          advance(start, move->second);
          advance(end, move->second);
        }
        break;
      }
      else
      {
        --size;
        --temp;
      }
    }
    if (temp == starttemp)
    {
      ++count;
      ++start;
      ++end;
    }
  }
  return count;

}



int main(int argc, char* argv[]) {
  fstream in(argv[1]);
  string input;
  string data;
  ifstream dat(argv[0]);
  while(getline(dat, input))
  {
    data  += input;

  }
  dat.close();
  while (getline(in, input))
  {
    cout << "input = |" << input << "|" << endl;
    map<char, int> skip(build(in, input));
    for (auto k : skip)
      cout << k.first << " aa" << k.second << " ";

    cout << search(skip, data, input) << endl;
    for (auto k : skip)
      cout << k.first << " aa" << k.second << " ";
  }
  return 0;
}
