#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    int height;
    Node *left;
    Node *right;

    Node(int data)
    {
        value = data;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

Node *getMinNode(Node *root)
{
    Node *curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *rightChild = child->right;

    child->right = root;
    root->left = rightChild;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *leftChild = child->left;

    child->left = root;
    root->right = leftChild;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }
    if (key < root->value)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->value)
    {
        return rightRotation(root);
    }
    else if (balance > 1 && key > root->left->value)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    else if (balance < -1 && key > root->right->value)
    {
        return leftRotation(root);
    }

    else if (balance < -1 && key < root->right->value)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    else
    {
        return root;
    }
}

Node *deletion(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (key < root->value)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right && root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            Node *temp = getMinNode(root->right);
            root->value = temp->value;
            root->right = deletion(root->right, temp->value);
        }
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1)
    {
        if (getBalance(root->left) >= 0)
        {
            return rightRotation(root);
        }
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (balance < -1)
    {
        if (getBalance(root->right) <= 0)
        {
            return leftRotation(root);
        }
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
    {
        return root;
    }
}

int height(Node *root)
{
    if (!root)
    {
        return -1;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);

    return 1 + max(lheight, rheight);
}

void printGivenLevel(Node *root, int level)
{
    if (!root)
    {
        return;
    }

    if (level == 0)
    {
        cout << root->value << " ";
    }
    else
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrder(Node *root)
{
    int h = height(root);

    for (int i = 0; i <= h; i++)
    {
        printGivenLevel(root, i);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrder(root);
    cout << endl;

    root = deletion(root, 40);
    cout << "After Deletion (40), In-order Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}