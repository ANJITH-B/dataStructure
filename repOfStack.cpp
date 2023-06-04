#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class stack {
    T stk[50];
    int top, maxsize;

public:
    stack(int size) {
        top = -1;
        maxsize = size;
    }

    void push(T item);
    void pop();
    void display();
    int is_empty();
    int is_full();
};

template <class T>
int stack<T>::is_empty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
void stack<T>::push(T item) {
    if (is_full())
        cout << "\n stack is full \n";
    else {
        top++;
        stk[top] = item;
    }
}

template <class T>
void stack<T>::pop() {
    if (is_empty())
        cout << "\n stack is empty \n";
    else {
        cout << "\n popped element is " << stk[top] << endl;
        top--;
    }
}

template <class T>
void stack<T>::display() {
    if (top == -1)
        cout << "Stack is empty";
    else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stk[i] << endl;
    }
}

template <class T>
int stack<T>::is_full() {
    if (top == maxsize - 1)
        return 1;
    else
        return 0;
}

int main() {
    int item, maxsize, choice = 0;
    cout << "Enter maximum stack size: ";
    cin >> maxsize;
    stack<int> ch(maxsize);

    while (1) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                ch.push(item);
                break;
            case 2:
                ch.pop();
                break;
            case 3:
                ch.display();
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}

