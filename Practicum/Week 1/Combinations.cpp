#include<iostream>
#include<vector>

void pr(std::vector<int> combination) {
  for(int i = 0; i < combination.size(); i++) {
    std::cout << combination[i] << " ";
  }
  std::cout << std::endl;
}

void generateCombination(int currNum, std::vector<int> combination, int n, int k) {
  if(currNum + k - combination.size() - 1 > n)
    return;
  if(combination.size() >= k) {
    pr(combination);
    return;
  }
  combination.push_back(currNum);
  generateCombination(currNum + 1, combination, n, k);
  combination.pop_back();
  generateCombination(currNum + 1, combination, n, k);
}

void prCombinations(int n, int k) {
  generateCombination(1, {}, n, k);
}

int main() {
  int n, k;
  std::cin >> n >> k;
  prCombinations(n, k);
  return 0;
}
