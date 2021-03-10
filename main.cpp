#include <iostream>
#include <vector>
#include <string>

int dipSearch(std::vector<int>);
std::vector<int> longestBalancedSpan(std::vector<int>);
std::string telegraphConvert(std::string);

int main() {
  std::vector<int> vector { 3, 2, 5, 4, 5, 3, 2, 1, 0, 2, -3, -5, -3 };
  std::cout << dipSearch(vector) << "\n";
  std::cout << telegraphConvert("ab#c");
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
  std::string telegraph = "";

  for (int i = 0; i < s.length(); ++i) {
    char ch = s.at(i);
    
    if (ch == ' ' && s.at(i + 1) && (i + 1 < s.length())) {
      continue;
    }

    if (ch == )

    if (ch - '0' >= 97 && ch - '0' <= 122) {
      telegraph.push_back(toupper(ch));
    } else if (ch == '!' || ch == '?' || ch == ';') {
      telegraph.push_back('.');
    } else {
      telegraph.push_back(ch);
    }
  }

  return telegraph;
}