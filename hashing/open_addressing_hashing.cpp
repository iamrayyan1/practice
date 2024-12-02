#include <iostream>
#include <vector>
//open addressing: linear,quadratic,double hashing
using namespace std;

class Hashing{
    public:

    vector<int> hashtable;
    int size;
    int empty = -1;

    Hashing(int size):size(size){
        hashtable.resize(size,empty);
    }

    //hash function
    int hashFunc(int key){
        return key%size;
    }

    //linear Probing: ek ek krke barhty hai agay if the current bucket is full.
    void linearProbing(int key){
        int index = hashFunc(key);
        int i = 0;
          //when collision occurs and the index is already full, we will move to the next empty space by adding one to the index and taking its mod then, newest free index will be the place where we store our next digit.
        while(hashtable[(index + i) %size] != empty){ 
            i++;
            if(i==size){
                cout<<"Table is full"<<endl;
                return;
            }
        }
        hashtable[(index+i)%size]=key; //newest index pe key store krarahy
    }

    //quadratic probing:takay ek he jagah cluster na banay:
    void quadraticProbing(int key){
        int index = hashFunc(key);
        int i = 0;

        while(hashtable[(index+i*i)%size] != empty){
            i++;
            if(i==size){
                cout<<"table full"<<endl;
                return;
            }
        }
        hashtable[(index+i*i)%size]=key;
    }

    //double hashing

    //new hashing function:
    int hashFunc2(int key){
      return  7 - (key%7); //humesha prime number lena is preferrable, also it should be less than the size of the table
    }

    void doubleHashing(int key){
        int index = hashFunc(key);
        int new_index = hashFunc2(key);
        int i=0;

        while(hashtable[(index+i*new_index)%size]!=empty){
            i++;
            if(i==size){
                cout<<"table full"<<endl;
                return;
            }
        }
        hashtable[(index+i*new_index)%size]=key;
    }

    void display(){
        for(int i=0;i<size;i++){
            if(hashtable[i]==empty){
                cout<<"index " << i << ": empty" <<endl;
            }
            else{
                cout<<"index "<< i <<": " <<hashtable[i] << endl;
            }
        }
    }
};

int main(){
    Hashing ht(10);
    cout<<'linaer'<<endl;
    ht.linearProbing(5);
    ht.linearProbing(125);
    ht.linearProbing(15);
    ht.linearProbing(55);
    ht.linearProbing(45);
    ht.display();

    Hashing ht2(10);
    cout<<"Quadratic"<<endl;
    ht2.quadraticProbing(5);
    ht2.quadraticProbing(125);
    ht2.quadraticProbing(15);
    ht2.quadraticProbing(55);
    ht2.quadraticProbing(45);
    ht2.display();

    Hashing ht3(10);
    cout<<"Double"<<endl;
    ht3.doubleHashing(5);
    ht3.doubleHashing(125);
    ht3.doubleHashing(15);
    ht3.doubleHashing(55);
    ht3.doubleHashing(45);
    ht3.display();


}