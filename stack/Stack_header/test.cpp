#include <iostream>
#include "stack.h"
using namespace std;


// run as g++ test.cpp stack.cpp -o test

int main() {
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');

    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;
    s.displayStack();

    if (s.pop() == '\0') {
        cout << "Stack is now empty." << endl;
    }

    s.push('d');
    s.push('e');
    cout << "Top element after pushing more elements: " << s.pop() << endl;
    s.displayStack();

    return 0;
}
