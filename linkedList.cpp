#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Linkadt {
private:
    struct Node {
        T val;
        Node* link;
    };
    
    Node* head;

public:
    Linkadt() {
        head = nullptr;
    }

    void insertBeg(T item) {
        Node* temp = new Node();
        temp->val = item;
        temp->link = head;
        head = temp;
    }

    void insertLast(T item) {
        Node* temp = new Node();
        temp->val = item;
        temp->link = nullptr;

        if (head == nullptr) {
            head = temp;
        }
        else {
            Node* ptr = head;
            while (ptr->link != nullptr) {
                ptr = ptr->link;
            }
            ptr->link = temp;
        }
    }

    void insertPos(T item, int pos) {
        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        Node* temp = new Node();
        temp->val = item;

        if (pos == 1) {
            temp->link = head;
            head = temp;
        }
        else {
            Node* ptr = head;
            int count = 1;
            while (count < pos - 1 && ptr != nullptr) {
                ptr = ptr->link;
                count++;
            }

            if (ptr == nullptr) {
                cout << "Position out of range.\n";
                delete temp;
                return;
            }

            temp->link = ptr->link;
            ptr->link = temp;
        }
    }

    T deleteBeg() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return T();
        }

        Node* temp = head;
        T item = temp->val;
        head = head->link;
        delete temp;
        return item;
    }

    T deleteLast() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return T();
        }

        if (head->link == nullptr) {
            T item = head->val;
            delete head;
            head = nullptr;
            return item;
        }

        Node* ptr = head;
        while (ptr->link->link != nullptr) {
            ptr = ptr->link;
        }

        T item = ptr->link->val;
        delete ptr->link;
        ptr->link = nullptr;
        return item;
    }

    T deletePos(int pos) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return T();
        }

        if (pos <= 0) {
            cout << "Invalid position.\n";
            return T();
        }

        if (pos == 1) {
            Node* temp = head;
            T item = temp->val;
            head = head->link;
            delete temp;
            return item;
        }

        Node* ptr = head;
        int count = 1;
        while (count < pos - 1 && ptr != nullptr) {
            ptr = ptr->link;
            count++;
        }

        if (ptr == nullptr || ptr->link == nullptr) {
            cout << "Position out of range.\n";
            return T();
        }

        Node* temp = ptr->link;
        T item = temp->val;
        ptr->link = temp->link;
        delete temp;
        return item;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }

    void find(const T& item) {
        Node* ptr = head;
        bool found = false;
        while (ptr != nullptr) {
            if (ptr->val == item) {
                found = true;
                break;
            }
            ptr = ptr->link;
        }
        if (found) {
            cout << "Item found in the list.\n";
        } else {
            cout << "Item not found in the list.\n";
        }
    }

    void findKth(int k) {
        if (k <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        Node* ptr = head;
        int count = 1;
        while (ptr != nullptr && count < k) {
            ptr = ptr->link;
            count++;
        }
        if (ptr == nullptr) {
            cout << "Position out of range.\n";
        } else {
            cout << "Value at position " << k << ": " << ptr->val << endl;
        }
    }

    void makeEmpty() {
        Node* ptr = head;
        while (ptr != nullptr) {
            Node* temp = ptr;
            ptr = ptr->link;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    Linkadt<int> link;

    int choice, item, pos;
    while (true) {
        cout << "\n1. Insert at the beginning";
        cout << "\n2. Insert at the end";
        cout << "\n3. Insert at a position";
        cout << "\n4. Delete from the beginning";
        cout << "\n5. Delete from the end";
        cout << "\n6. Delete from a position";
        cout << "\n7. Find item";
        cout << "\n8. Find value at kth position";
        cout << "\n9. Check if list is empty";
        cout << "\n10. Display list";
        cout << "\n11. Make the list empty";
        cout << "\n12. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to insert: ";
                cin >> item;
                link.insertBeg(item);
                break;
            case 2:
                cout << "Enter the item to insert: ";
                cin >> item;
                link.insertLast(item);
                break;
            case 3:
                cout << "Enter the item to insert: ";
                cin >> item;
                cout << "Enter the position: ";
                cin >> pos;
                link.insertPos(item, pos);
                break;
            case 4:
                item = link.deleteBeg();
                cout << "Deleted item: " << item << endl;
                break;
            case 5:
                item = link.deleteLast();
                cout << "Deleted item: " << item << endl;
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> pos;
                item = link.deletePos(pos);
                cout << "Deleted item: " << item << endl;
                break;
            case 7:
                cout << "Enter the item to find: ";
                cin >> item;
                link.find(item);
                break;
            case 8:
                cout << "Enter the position: ";
                cin >> pos;
                link.findKth(pos);
                break;
            case 9:
                if (link.isEmpty()) {
                    cout << "List is empty.\n";
                } else {
                    cout << "List is not empty.\n";
                }
                break;
            case 10:
                cout << "List: ";
                link.display();
                break;
            case 11:
                link.makeEmpty();
                cout << "List has been made empty.\n";
                break;
            case 12:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}


