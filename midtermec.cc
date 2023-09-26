#include <iostream>
#include <cstdint>

using namespace std;

int sumSq(const uint64_t a[], int len);

int main() {
  uint64_t x[] = {5, 12, 8, 7, 4};
  cout << sumSq(x, 5) << '\n'; // should compute 5*5 + 7*7 because those are the only two odd numbers
}