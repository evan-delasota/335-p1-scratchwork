#include <iostream>
#include <vector>
#include <string>

int dipSearch(std::vector<int>);
std::string telegraphConvert(std::string);

int main() {
  std::vector<int> vector { 3, 2, 5, 4, 5, 3, 2, 1, 0, 2, -3, -5, -3 };
  std::cout << dipSearch(vector) << "\n";
}

int dipSearch(std::vector<int> v) {
  int lastDip = v.at(0);
  for (int i = 0; i < v.size() - 3; ++i) {
    if (v.at(i) == v.at(i + 2) && v.at(i) > v.at(i + 1)) {
      lastDip = i;
    }
  }

  return lastDip;
}

std::string telegraphConvert(std::string s) {
  for (int i = 0; i < s.length(); ++i) {
    char ch = s.at(i);
  }
}