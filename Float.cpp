#include <iostream>
using namespace std;

template <class T>
class Array {
public:
    T assay[20];
    int size;

    void insert() {
        cout << "Enter size: ";
        cin >> size;

        cout << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            cin >> assay[i];
        } 
    }

    void printAssay() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << assay[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int> t1;
    t1.insert();
    t1.printAssay();

    Array<float> t2;
    t2.insert();
    t2.printAssay();

    return 0;
}
