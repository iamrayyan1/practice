#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Chaining
class Hashing
{
public:
    vector<list<int>> hashtable;
    int size;

    Hashing(int s)
    {
        size = s;
        hashtable.resize(s);
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunc(key);
        hashtable[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunc(key);
        hashtable[index].remove(key);
    }

    void search(int key)
    {
        int index = hashFunc(key);
        for (int ele : hashtable[index])
        {
            if (ele == key)
            {
                cout << "Found" << endl;
                return;
            }
        }
        cout << "Not Found" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            for (int key : hashtable[i])
            {
                cout << key << "->";
            }
            cout << "NULL" << endl;
        }
    }
};

// probing

class Hashing
{
public:
    vector<int> hashtable;
    int empty = -1;
    int size;

    Hashing(int s)
    {
        size = s;
        hashtable.resize(s, empty);
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    // linear probing
    void insert(int key)
    {
        int index = hashFunc(key);
        int i = 0;

        while (hashtable[(index + i) % size] != empty)
        {
            i++;
            if (i == size)
            {
                cout << "HashTable is Full" << endl;
                return;
            }
        }
        hashtable[(index + i) % size] = key;
    }

    // quad probing
    void insert(int key)
    {
        int index = hashFunc(key);
        int i = 0;

        while (hashtable[(index + i * i) % size] != empty)
        {
            i++;
            if (i == size)
            {
                cout << "Table full";
                return;
            }
        }
        hashtable[(index + i * i) % size] = key;
    }

    // double hashing
    int hashFunc2(int key)
    {
        return 7 - (key % 7);
    }

    void doubleHash(int key)
    {
        int index = hashFunc(key);
        int new_index = hashFunc2(key);
        int i = 0;

        while (hashtable[(index + i * new_index) % size] != empty)
        {
            i++;
            if (size == i)
            {
                cout << "Table full";
                return;
            }
        }
        hashtable[(index + i * new_index) % size] = key;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (hashtable[i] == empty)
            {
                cout << "Index " << i << ": Empty" << endl;
            }
            else
            {
                cout << "Index " << i << ": " << hashtable[i] << endl;
            }
        }
    }
};

// rehash
class Hashing
{
public:
    vector<list<int>> hashtable;
    int size;
    int count;

    Hashing(int s)
    {
        size = s;
        hashtable.resize(s);
        count = 0;
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    void rehash()
    {
        int oldSize = size;
        size *= 2;

        vector<list<int>> newTable(size);

        for (int i = 0; i < oldSize; i++)
        {
            for (int key : hashtable[i])
            {
                int new_index = hashFunc(key);
                newTable[new_index].push_back(key);
            }
        }
        hashtable = move(newTable);
        cout << "Rehashing done size" << size << endl;
    }

    void insert(int key)
    {
        int index = hashFunc(key);
        hashtable[index].push_back(key);

        count++;
        double loadFactor = (double)count / size;
        if (loadFactor > 0.75)
        {
            cout << "Rehash" << endl;
            rehash();
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            for (int key : hashtable[i])
            {
                cout << key << "->";
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    Hashing chaining(10); // Chaining example
    chaining.insert(5);
    chaining.insert(15);
    chaining.display();

    Hashing probing(10); // Probing example
    probing.insertLinear(5);
    probing.insertLinear(15);
    probing.display();

    Hashing rehashing(5); // Rehashing example
    rehashing.insert(10);
    rehashing.insert(20);
    rehashing.insert(30);
    rehashing.insert(40); // Triggers rehash
    rehashing.display();

    return 0;
}
