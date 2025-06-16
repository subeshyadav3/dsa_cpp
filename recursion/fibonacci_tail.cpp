#include <iostream>
using namespace std;

int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    return fibonacciTail(n - 1, b, a + b);
}4

int main() {
    int n;
    cout << "Enter the term: ";
    cin >> n;
    cout << "Fibonacci (Tail Recursion) at position " << n << " is " << fibonacciTail(n);
    return 0;
}
