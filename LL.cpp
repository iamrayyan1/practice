#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }

    friend class SLL;
    friend class DLL;
};

class SLL
{
    Node *head;

public:
    SLL()
    {
        head = NULL;
    }

    ~SLL()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value, int pos)
    {
        if (!head)
        {
            head = new Node(value);
        }
        else
        {
            if (pos == 1)
            {
                Node *temp = new Node(value);
                temp->next = head;
                head = temp;
            }
            else
            {
                Node *curr = head;
                while (--pos)
                {
                    curr = curr->next;
                }
                if (!curr->next)
                {
                    curr->next = new Node(value);
                }
                else
                {
                    Node *temp = new Node(value);
                    temp->next = curr->next;
                    curr->next = temp;
                }
            }
        }
    }

    void deletion(int pos)
    {
        if (!head)
        {
            return;
        }
        if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            delete temp;
        }
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            while (--pos)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
    }

    void search(int key)
    {
        // traverse through elements and search
    }
};

class DLL
{
    Node *head;

public:
    DLL()
    {
        head = NULL;
    }

    ~DLL()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int key, int pos)
    {
        if (!head)
        {
            head = new Node(key);
        }
        else
        {
            if (pos == 1)
            {
                Node *temp = new Node(key);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else
            {
                Node *curr = head;
                while (--pos)
                {
                    curr = curr->next;
                }
                if (!curr->next)
                {
                    Node *temp = new Node(key);
                    curr->next = temp;
                    temp->prev = curr;
                }
                else
                {
                    Node *temp = new Node(key);
                    temp->next = curr->next;
                    temp->prev = curr;
                    curr->next = temp;
                    temp->next->prev = temp;
                }
            }
        }
    }

    void deletion(int pos)
    {
        if (!head)
        {
            return;
        }
        else
        {
            if (pos == 1)
            {
                if (head->next == NULL)
                {
                    delete head;
                    head = NULL;
                }
                else
                {
                    Node *temp = head;
                    head = head->next;
                    head->prev = NULL;
                    delete temp;
                }
            }
            else
            {
                Node *curr = head;
                while (--pos)
                {
                    curr = curr->next;
                }
                if (!curr->next)
                {
                    curr->prev->next = NULL;
                    delete curr;
                }
                else
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
            }
        }
    }
};