// Moshe Moskowitz and Vincent Renda
// I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

// int
int gcd(int a, int b){
    int gcd = 1;
    int lower = a;
    int higher = b;
    if(a > b){
        lower = b;
        higher = a;
    }
    for (int i = 1; i <= lower; i++){
        if (lower % i == 0 && higher % i == 0){
            gcd = i;
        }
    }
    return gcd;
}
bool isPrime(int a){
    for (int i = 2; i < a; i++){
        if (a%i == 0){
            return false;
        }
    }
    if (a == 0 || a == 1){
        return false;
    }
    else{
        return true;
    }
}
int countPrimes(int a, int b){
    int num = 0;
    for (int i = a; i <= b; i++){
        if (isPrime(i) == true){
            num += 1;
        }
    }
    return num;
}
// double
double sum_forward(int n){
    double sum = 0;
    for (double i = 1; i <= n; i++){
        sum += (1/i);
    }
    return sum;
}
double sum_backward(int n){
    double sum = 0;
    for (double i = n; i >= 1; i--){
        sum += (1/i);
    }
    return sum;
}
double hypot(double a, double b){
    return (sqrt(a*a+b*b));
}
// array
void double_each(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] *=2 ;
    }
}
double mean(double x[], int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += x[i];
    }    
    double mean = sum/n;
    return mean;
}
int prod(int x[], int n){
    double prod = 1;
    for(int i = 0; i < n; i++){
        prod *= x[i];
    }    
    return prod;   
}


int main() {
    //------------------------integer part
    cout << "part 1 output:" << endl;
    cout << "gcd(12, 18)=" << gcd(12, 18) << endl;
    cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << endl;
    cout << "isPrime(5)=" << isPrime(5) << endl;
    cout << "isPrime(9)=" << isPrime(9) << endl;
    cout << "isPrime(1001)=" << isPrime(1001) << endl;
    cout << "isPrime(2601)=" << isPrime(2601) << endl;
    cout << "isPrime(1013)=" << isPrime(1013) << endl;
    cout << "countPrimes(1,100): " << countPrimes(1, 100) << endl;
    cout << "countPrimes(1,10000): " << countPrimes(1, 10000) << endl;
    
    //------------------------doubleing point number part
    cout << "part 2 output:" << endl;
    double ans_1 = sum_forward(100);
    double ans_2 = sum_backward(100);
    cout << setprecision(8)<< ans_1 << endl;
    cout << setprecision(8) << ans_2 << endl;
    cout << "hypot(3,4)=" << hypot(3, 4) << endl; // should print 5
    cout << "hypot(4,5)=" << hypot(4, 5) << endl;
    //------------------------array part
    cout << "part 3 output:" << endl;
    double x[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(x)/sizeof(double);
    cout << mean(x, n) << endl; // should print 35
    double y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(double)) << endl; // should print 2.5
    int z[] = {10, 20, 30, 40, 50, 60};
    int z_len = sizeof(z)/sizeof(int);
    double_each(z, z_len);
    for (int i = 0; i < z_len; i++) {
        cout << z[i] << ",";
    }
    cout << endl;
    int a[] = {3, 4, 1, 2, -2};
    cout << prod(a, sizeof(a)/sizeof(int)) << endl;
    int b[] = {2, 4, 8, -2, -4};
    cout << prod(b, sizeof(b)/sizeof(int)) << endl;
    
    return 0;
}
