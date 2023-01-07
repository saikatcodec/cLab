#include <cmath>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number: ";
    int n;
    cin >> n;
    double temp = log10(n) / log10(3);  // equivalent to log3(n)
    cout << ((temp - (int)temp) < 1e-9 ? "true" : "false") << '\n';
    return 0;
}