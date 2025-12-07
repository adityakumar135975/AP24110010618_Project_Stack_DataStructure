#include <iostream>
using namespace std;

int top = -1;

void isEmpty(int arr[]) {
    if (top == -1)
        cout << "Empty!" << endl << endl;
    else
        cout << "Not empty!" << endl << endl;
}

void isFull(int arr[], int max) {
    if (top == max - 1)
        cout << "Full!" << endl << endl;
    else
        cout << "Not Full!" << endl << endl;
}

void push(int arr[], int max) {
    if (top == max - 1) {
        cout << "Full stack! The value cannot be pushed!" << endl << endl;
        return;
    }
    cout << "Enter the value to be pushed: ";
    int val;
    cin >> val;
    top++;
    arr[top] = val;
}

void pop(int arr[]) {
    if (top == -1) {
        cout << "Empty Stack! Stack Underflow!" << endl << endl;
        return;
    }
    int removed = arr[top];
    top--;
    cout << removed << " popped from stack." << endl << endl;
}

void peek(int arr[]) {
    if (top == -1) {
        cout << "Empty stack, nothing to see." << endl << endl;
        return;
    }
    cout << "Value on top = " << arr[top] << endl << endl;
}

void display(int arr[]) {
    if (top == -1) {
        cout << "The stack is empty." << endl << endl;
        return;
    }
    cout << "The elements (from the top to the end) are: ";
    for (int i = top; i >= 0; i--)
        cout << arr[i] << "\t";
    cout << endl << endl;
}

void sizeOfStack() {
    cout << "Current size = " << top + 1 << endl << endl;
}

int main() {
    int max;
    cout << "Enter the maximum number of elements the stack can store: ";
    cin >> max;
    while(max<0)
    {
        cout<<"The capacity can't be negative. Please recheck and enter again: ";
        cin>>max;
    }
    cout << endl;

    int arr[max];
    char choice;

    cout << "A for Push" << "\t" << "B for Pop" << "\t" << "C for Peek" << endl;
    cout << "D for Display" << "\t" << "E for isEmpty" << "\t" << "F for isFull" << endl;
    cout << "G for Size" << "\t" << "Q to Quit" << endl;

    while (true) {
        cout << endl << "Enter your choice: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a')
            push(arr, max);
        else if (choice == 'B' || choice == 'b')
            pop(arr);
        else if (choice == 'C' || choice == 'c')
            peek(arr);
        else if (choice == 'D' || choice == 'd')
            display(arr);
        else if (choice == 'E' || choice == 'e')
            isEmpty(arr);
        else if (choice == 'F' || choice == 'f')
            isFull(arr, max);
        else if (choice == 'G' || choice == 'g')
            sizeOfStack();
        else if (choice == 'Q' || choice == 'q')
            return 0;
        else
            cout << "Wrong input! Try again." << endl << endl;
    }
}
