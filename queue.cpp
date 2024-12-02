#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == size - 1;
    }

    void push(int x)
    { // at the end
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
        else if (isFull())
        {
            cout << "Queue Overflow." << endl;
            return;
        }
        else
        {
            rear += 1;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
    }

    void pop()
    { // from the start
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = rear = -1;
            }
            else
            {
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front += 1;
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

// Circular Queue

class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % size == front; //
    }

    void push(int x)
    { // at the end
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
        else if (isFull())
        {
            cout << "Queue Overflow." << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % size; //
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue" << endl;
        }
    }

    void pop()
    { // from the start
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = rear = -1;
            }
            else
            {
                cout << "Popped " << arr[front] << " out of the Queue" << endl;
                front = (front + 1) % size; //
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

// LINKED LIST IMPLEMENTATION

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            cout << "Pushed " << x << " into the Queue" << endl;
            front = new Node(x);
            rear = front;
            return;
        }
        else
        {
            rear->next = new Node(x);
            if (rear->next == NULL)
            {
                cout << "Queue Overflow\n";
                return;
            }
            cout << "Pushed " << x << " into the Queue" << endl;
            rear = rear->next;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow " << endl;
            return;
        }
        else
        {
            cout << "Popped " << front->data << " out of the Queue" << endl;
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow " << endl;
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    // if question has told us the fix size of the queue then just make a int count varaible and increment and decrement it whenever performing push and pop function
};

// Stack Implementation
class Queue
{
    stack<int> st1;
    stack<int> st2;

public:
    bool empty()
    {
        return st1.empty() && st2.empty();
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (empty())
        {
            return 0;
        }
        else if (!st2.empty())
        {
            int element = st2.top();
            st2.pop();
            return element;
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int element = st2.top();
            st2.pop();
            return element;
        }
    }

    int peek()
    { // always check top of stack 2 (similar logic as pop)
        if (empty())
        {
            return 0;
        }
        if (!st2.empty())
        {
            return st2.top();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};