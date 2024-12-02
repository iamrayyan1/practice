#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int s)
    {
        arr = new int[s];
        size = 0;
        total_size = s;
    }

    ~MaxHeap()
    {
        delete[] arr;
    }

    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << value << " is inserted into the heap" << endl;
    }

    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    void buildHeap(int inputArr[], int n)
    {
        if (n > total_size)
        {
            cout << "Input array size exceeds heap capacity\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = inputArr[i];
        }

        size = n;

        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void print()
    {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap(10);

    heap.insert(50);
    heap.insert(30);
    heap.insert(20);
    heap.insert(15);
    heap.insert(10);
    heap.insert(8);
    heap.insert(16);

    heap.print();

    heap.deleteRoot();
    heap.print();

    int arr[] = {3, 9, 2, 1, 4, 5};
    heap.buildHeap(arr, 6);
    heap.print();

    return 0;
}

// HEAP SORT

void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root (maximum element) to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/*
LINKED LIST IMPLEMENTATION:


#include <iostream>
#include <queue> // For level-order traversal
using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;

    Node(int val)
    {
        value = val;
        left = right = nullptr;
    }
};

class MaxHeap
{
private:
    Node *root;

    // Helper function to swap values between two nodes
    void swapValues(Node *a, Node *b)
    {
        int temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

    // Helper function to heapify upwards
    void heapifyUp(Node *node)
    {
        if (!node || !node->parent)
            return;

        if (node->value > node->parent->value)
        {
            swapValues(node, node->parent);
            heapifyUp(node->parent);
        }
    }

    // Helper function to heapify downwards
    void heapifyDown(Node *node)
    {
        if (!node)
            return;

        Node *largest = node;

        if (node->left && node->left->value > largest->value)
            largest = node->left;

        if (node->right && node->right->value > largest->value)
            largest = node->right;

        if (largest != node)
        {
            swapValues(node, largest);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() : root(nullptr) {}

    // Insert a new value into the heap
    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
            return;
        }

        // Perform a level-order traversal to find the correct insertion point
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (!curr->left)
            {
                curr->left = new Node(value);
                heapifyUp(curr->left);
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (!curr->right)
            {
                curr->right = new Node(value);
                heapifyUp(curr->right);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }

    // Extract the maximum value (root of the heap)
    int extractMax()
    {
        if (!root)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int maxValue = root->value;

        // Find the rightmost leaf to replace the root
        queue<Node *> q;
        q.push(root);

        Node *lastNode = nullptr, *parent = nullptr;
        while (!q.empty())
        {
            lastNode = q.front();
            q.pop();

            if (lastNode->left)
            {
                parent = lastNode;
                q.push(lastNode->left);
            }
            if (lastNode->right)
            {
                parent = lastNode;
                q.push(lastNode->right);
            }
        }

        // Replace root with the last node's value
        if (lastNode)
        {
            root->value = lastNode->value;

            // Remove the last node
            if (parent && parent->right == lastNode)
            {
                delete parent->right;
                parent->right = nullptr;
            }
            else if (parent && parent->left == lastNode)
            {
                delete parent->left;
                parent->left = nullptr;
            }
            else
            {
                delete root;
                root = nullptr;
            }

            // Heapify down from the root
            heapifyDown(root);
        }

        return maxValue;
    }

    // Display the heap in level-order
    void printLevelOrder()
    {
        if (!root)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->value << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap;

    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(10);
    heap.insert(8);
    heap.insert(25);

    cout << "Heap elements (level-order): ";
    heap.printLevelOrder();

    cout << "Extracted max: " << heap.extractMax() << endl;

    cout << "Heap elements after extraction (level-order): ";
    heap.printLevelOrder();

    return 0;
}


*/