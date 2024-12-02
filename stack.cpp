
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Implement it with array
class Stack
{
private:
    int *arr; // DMA
    int size;
    int top;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow";
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << "into the stack\n";
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
            return;
        }
        else
            top--;
        cout << "Popped " << arr[top + 1] << "from the stack\n";
    }

    int peak()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
            return -1;
        }
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return top == -1; // if empty return 1
    }

    bool isFull()
    {
        return top == size - 1;
    }

    int isSize()
    {
        return top + 1;
    }
};

// Linked List Implementation

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int value)
    {
        data = value;
        next = NULL;
    }

    friend class Stack;
};

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0; // since size is not a restriction in Linked List
    }

    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "Stack Overflow";
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed" << value << " into the stack";
        }
    }
    // stack will only overflow when heap memory is full

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
            return;
        }
        else
        {
            Node *temp = top;
            cout << "popped" << top->data << " out of the stack";
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peak()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        return top == NULL; // returns 1 if empty
    }

    int isSize()
    {
        return size;
    }
};

// Queue implementation

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    bool empty()
    {
        return q1.empty() && q2.empty();
    }

    void push(int x)
    {
        if (empty())
        {
            q1.push(x); // kisi ko bhi choose ker sakte
        }
        else if (q1.empty())
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }

    int pop()
    {
        if (empty())
        {
            return 0;
        }
        else if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q2.front());
                q1.pop();
            }
            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top()
    {
        // stack khali hou
        if (empty())
        {
            return 0;
        }
        else if (q1.empty())
        {
            return q2.back(); // last element
        }
        else
        {
            return q1.back();
        }
    }
};
