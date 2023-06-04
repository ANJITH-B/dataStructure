#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class queue
{
    int front, rear, maxsize;
    T que[100];

public:
    queue(int n);
    int isFull();
    int isEmpty();
    void enqueue(T item);
    void dequeue();
    void display();
};

template<class T>
queue<T>::queue(int n)
{
    maxsize = n;
    front = 0;
    rear = -1;
}

template<class T>
int queue<T>::isFull()
{
    if (rear == maxsize - 1)
        return 1;
    else
        return 0;
}

template<class T>
int queue<T>::isEmpty()
{
    if (front > rear)
        return 1;
    else
        return 0;
}

template<class T>
void queue<T>::enqueue(T item)
{
    if (isFull())
    {
        cout << "\nQueue full";
    }
    else
    {
        rear++;
        que[rear] = item;
    }
}

template<class T>
void queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << "Item deleted: " << que[front];
        front++;
    }
}

template<class T>
void queue<T>::display()
{
    if (isEmpty())
    {
        cout << "\nQueue is empty";
    }
    else
    {
        cout << "\nQueue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << que[i] << " ";
        }
    }
}

int main()
{
    int ch, item, n;
    cout << "Enter maximum size: ";
    cin >> n;

    queue<int> q(n);

    while (1)
    {
        cout << "\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter item: ";
            cin >> item;
            q.enqueue(item);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(0);
        }
    }
    return 0;
}
