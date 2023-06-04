#include <iostream>

using namespace std;

template <class t>
class Qlink {
    class Node {
    public:
        t val;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Qlink();
    void enqueue(t item);
    t dequeue();
    void display();
};

template <class t>
Qlink<t>::Qlink() {
    front = nullptr;
    rear = nullptr;
}

template <class t>
void Qlink<t>::enqueue(t item) {
    Node* temp = new Node();
    temp->val = item;
    temp->next = nullptr;

    if (front == nullptr) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

template <class t>
t Qlink<t>::dequeue() {
    if (front == nullptr) {
        cout << "\n Linked queue is empty";
        // Return a default value for type t
        return t();
    } else {
        Node* p = front;
        t value = front->val;
        front = front->next;
        delete p;
        return value;
    }
}

template <class t>
void Qlink<t>::display() {
    if (front == nullptr) {
        cout << "Linked queue is empty";
    } else {
        Node* ptr = front;
        while (ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main() {
    Qlink<int> link;
    int ch, item;

    while (1) {
        cout << "Linked Queue ADT" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter item to enqueue: ";
                cin >> item;
                link.enqueue(item);
                break;
            case 2:
                link.dequeue();
                break;
            case 3:
                link.display();
                break;
            case 4:
                return 0;
        }
    }
}
