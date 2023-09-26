#include <iostream>
using namespace std;

double function(float a, float b, double c, double d){
    return a+b+c+d;
}

int main(){
    cout << function(1.1,2.2,3.3,4.5);
}