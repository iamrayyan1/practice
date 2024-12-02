#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hashing{
    public:
    vector<list<int> > hashtable;
    int size;
    int count;

    Hashing(int size):size(size),count(0) {
        hashtable.resize(size);
    }

    int hashFunc(int key){
        return key % size;
    }
    void rehash(){
        int oldsize=size;
        size*=2;
        vector<list<int> > newTable(size);
        //inserting elements into new table of double size
        for(int i=0;i<oldsize;i++){
            for(int key:hashtable[i]){
                int new_index=key % size;
                newTable[new_index].push_back(key);
            }
        }
        hashtable = move(newTable);
        cout<<"Rehashing done size: " << size<<endl;
    }

    void insert(int key){
        int index = hashFunc(key);
        hashtable[index].push_back(key);
        count++;

        double loadfactor = (double)count/size;
        cout<<"inserted " << key << "load factor" <<loadfactor << endl;
        if(loadfactor>0.75){
            cout<<"rehash!!" << endl;
            rehash();
        }
    }

    void display(){
        for(int i=0; i<size;i++){
            cout<<"index "<<i<<": ";
            for(int key : hashtable[i]){
                cout<<key<<"-> ";
            }
             cout << "NULL" << endl; 
        }
    }
};

int main(){
   Hashing ht(5);  // Initial size of 5

   ht.insert(10);
    ht.insert(20);
    ht.insert(32);
    ht.insert(4);
    ht.insert(24);
    ht.insert(6);  // Will trigger rehashing
    ht.insert(79);

    cout << "\nHash Table after rehashing:\n";
    ht.display();


    return 0;
}
