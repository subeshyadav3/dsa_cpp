#include <iostream>
using namespace std;

int factorialTail(int n, int result = 1) {
    if (n == 0)
        return result;
    return factorialTail(n - 1, result * n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial (Tail Recursion) of " << n << " is " << factorialTail(n);
    return 0;
}
