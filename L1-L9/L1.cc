#include <iostream>

double product(const int a[], int n) {
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= a[i];
    }
    return result;
}
//hello
int main() {
  int a[] = {5, 3, 1, 9};
  double z = product(a, 4);
  std::cout << z << '\n';
  return 0;
}
