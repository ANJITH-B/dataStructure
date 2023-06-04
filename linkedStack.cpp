#include <iostream>
using namespace std;
template<class T>
class LinkStack {
    class Node {
    public:
        T val;
        Node* link;
    };
    Node* top;
    
public:
    LinkStack();
    void push(T item);
    T pop();
    void display();
};

template<class T>
LinkStack<T>::LinkStack() {
    top = NULL;
}

template<class T>
void LinkStack<T>::push(T item) {
    Node* temp = new Node();
    temp->val = item;
    temp->link = NULL;
    if (top == NULL) {
        top = temp;
    }
    else {
        temp->link = top;
        top = temp;
    }
}

template<class T>
T LinkStack<T>::pop() {
    if (top == NULL) {
        cout <<"Linked stack is empty" << endl;
    }
    else {
        Node* p = top;
        cout << "\n" << top->val;
        top = top->link;
        delete p;
    }
}

template<class T>
void LinkStack<T>::display() {
    if (top == NULL) {
        cout <<"Linked Stack is empty";
    }
    else {
        Node* Ptr = top;
        while (Ptr != NULL) {
            cout << "\n" << Ptr->val;
            Ptr = Ptr->link;
        }
    }
}

int main() {
    LinkStack<int> lnk;
    int ch, item;
    while (1) {
        cout << "\n In Linked Stack ADT" << endl;
        cout << "\n1-Push \n2-Pop \n3-Display \n4-Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter item: ";
                cin >> item;
                lnk.push(item);
                break;
            case 2:
                lnk.pop();
                break;
            case 3:
                lnk.display();
                break;
            case 4:
                return 0;
        }
    }
}

