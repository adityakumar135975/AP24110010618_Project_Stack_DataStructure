#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int top = -1;

void push(char stack[], char ch) {
    stack[++top] = ch;
}

void pop(char stack[]) {
    if (top != -1)
        top--;
}

int main() {
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);

    top = -1;

    int count = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == ')' ||
            expression[i] == '[' || expression[i] == ']' ||
            expression[i] == '{' || expression[i] == '}')
        {
            count++;
        }
    }

    if (count % 2 != 0 || count == 0) {
        cout << "Incorrect syntax! Uneven or zero brackets.";
        return 0;
    }

    char brackets[count];
    int j = 0;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == ')' ||
            expression[i] == '[' || expression[i] == ']' ||
            expression[i] == '{' || expression[i] == '}')
        {
            brackets[j++] = expression[i];
        }
    }

    if (brackets[0] == ']' || brackets[0] == '}' || brackets[0] == ')') {
        cout << "Incorrect syntax! Wrong first index.";
        return 0;
    }

    if (brackets[count - 1] == '[' || brackets[count - 1] == '{' || brackets[count - 1] == '(') {
        cout << "Incorrect syntax! Wrong last index.";
        return 0;
    }

    char stack[count];
    top = -1;

    for (int i = 0; i < count; i++) {

        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            push(stack, brackets[i]);
        }

        else if (
            (brackets[i] == ')' && stack[top] == '(') ||
            (brackets[i] == ']' && stack[top] == '[') ||
            (brackets[i] == '}' && stack[top] == '{')
        ) {
            pop(stack);
        }

        else {
            cout << "Incorrect syntax!";
            return 0;
        }
    }

    if (top == -1)
        cout << "Correct syntax!";
    else
        cout << "Incorrect syntax!";

    return 0;
}
