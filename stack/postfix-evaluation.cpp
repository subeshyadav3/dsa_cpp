#include <bits/stdc++.h>
#define SIZE 100
using namespace std;

int tos = -1;
int myStack[SIZE];

void push(int a) {
    if (tos >= SIZE - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        myStack[++tos] = a;
    }
}

int pop() {
    if (tos < 0) {
        cout << "Stack is Empty!" << endl;
        return 0;
    } else {
        return myStack[tos--];
    }
}

int main() {
    char post[SIZE];
    int i = 0;

    cout << "Enter PostFix Expression: ";
    cin >> post;

    cout << "Postfix Expression: " << post << endl;

    for (i = 0; post[i] != '\0'; i++) {
        if (isdigit(post[i])) {
            push(post[i] - '0'); 
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (post[i]) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    if (val2 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return 1;
                    }
                    push(val1 / val2);
                    break;
                case '^':
                    push(pow(val1, val2));
                    break;
                default:
                    cout << "Error: Invalid operator '" << post[i] << "'" << endl;
                    return 1;
            }
        }
    }

    cout << "Result: " << pop() << endl;
    return 0;
}
