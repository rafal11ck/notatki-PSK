#include <iostream>

int main() {
  int a{};
  int s{1};
  std::cin >> a;
  while (a!=0){
    s *= a;
    std::cin >> a;
  };
  std::cout << s;
}
