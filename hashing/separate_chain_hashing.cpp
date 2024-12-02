//basic hashing using separate chaining jisme linked list ke through insertion hoti hai
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hashing{
    public:
    vector<list<int> > hashtable;
    int size;

    Hashing(int size) : size(size){
        hashtable.resize(size);
    }

    int hashFunc(int key){
        return key%size;
    }

    //insertion: we'll assign the mod's value to the index where the key will be stored. jab key%size kiya tou rem aya us rem pe value store hogi, woh rem ki value hashtable ke index ko assign kreke pushback karadia
    void insert(int key){
        int index = hashFunc(key);
        hashtable[index].push_back(key);
    }

    void remove(int key){
        int index = hashFunc(key);
        hashtable[index].remove(key); //removes all occurences of that key from the bucket
    }

    void search(int key) {
    int index = hashFunc(key);
    for (int ele : hashtable[index]) { // Iterate over the list at the computed index
        if (ele == key) {
            cout << "Found" << endl;
            return;  // Key found, exit the function
        }
    }
    cout << "Not Found" << endl;
}


    void display() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        // Loop through each element in the list (bucket) at index i
        for (int key : hashtable[i]) {
            cout << key << " -> ";
        }
        cout << "NULL" << endl; // End of the list
    }
}
};

int main(){
    Hashing ht(10);
    ht.insert(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(40);
    ht.insert(4);
    ht.insert(8);
    ht.insert(9);
    ht.insert(10);

    std::cout << "Hash Table:" << std::endl;
    ht.display();

    int key = 15;
    ht.search(15);

    ht.remove(15);
    cout << "\nAfter removing key " << key << ":" << endl;
    ht.display();

    return 0;
}
