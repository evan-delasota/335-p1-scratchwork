#include <iostream>
#include <vector>
#include <string>

int dipSearch(std::vector<int>);
std::vector<int> longestBalancedSpan(std::vector<int>);
std::string telegraphConvert(std::string);

int main() {
  std::vector<int> result;
  std::vector<int> vector { 3, 2, 5, 4, 5, 3, 2, 1, 0, 2, -3, -7, -3 };
  std::cout << dipSearch(vector) << "\n";

  result = longestBalancedSpan(vector);
  std::cout << result.at(0) << " " << result.at(1) << "\n";

  std::cout << telegraphConvert("ab#      !?!?c!  ?2?   !") << "\n";
  std::cout << telegraphConvert("ab#  ?ccb!  ?2?STOP");  
}

int dipSearch(std::vector<int> v) {
  int lastDip = v.at(0);
  for (int i = 0; i < v.size() - 2; ++i) {
    if (v.at(i) == v.at(i + 2) && v.at(i) > v.at(i + 1)) {
      lastDip = i;
    }
  }

  return lastDip;
}

std::vector<int> longestBalancedSpan(std::vector<int> v) {
  std::vector<int> best;
  int sum = 0;
  int subArrayMin = 0;
  int subArrayMax = 0;

  for (int s = 0; s < v.size(); ++s) {
    sum = v.at(s);
    for (int e = s + 1; e < v.size(); ++e) {
      sum += v.at(e);
      if (sum == 0 && (e - s) > (subArrayMax - subArrayMin)) {
        subArrayMax = e;
        subArrayMin = s;
      }
    }
  }
  best.push_back(subArrayMin);
  best.push_back(subArrayMax);
  return best;
}
std::string telegraphConvert(std::string s) {
  if (s.length() == 0) {
    return s;
  }

  std::string telegraph = "";

  for (int i = 0; i < s.length(); ++i) {
    char ch = s.at(i);
    bool firstSpace = true;

    while (ch == ' ' && s.at(i + 1) == ' ' && (i + 1 < s.length())) {
      if (firstSpace) {
        telegraph.push_back(ch);
        firstSpace = false;
      }
      i++;
    }

    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')) {
      telegraph.push_back(ch);
    } else if (ch >= 'a' && ch <= 'z') {
      telegraph.push_back(toupper(ch));
    } else if (ch == '!' || ch == '?' || ch == ';') {
      telegraph.push_back('.');
    } else {
      continue;
    }
  }

  if (s.substr((s.length() - 4), s.length()) != "STOP") {
    telegraph.append("STOP");    
  }

  return telegraph;
}