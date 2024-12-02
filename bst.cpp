// BST
#include <iostream>
#include <vector>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    void inorder(Node *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    Node *insert(Node *root, int value)
    {
        if (!root)
        {
            return new Node(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    bool searchNode(Node *root, int value)
    {
        if (!root)
        {
            return 0;
        }
        if (root->data == value)
        {
            return 1;
        }
        else if (value < root->data)
        {
            return searchNode(root->left, value);
        }
        else
        {
            return searchNode(root->right, value);
        }
        return 0;
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
            cout << root->data << " ";
        }
        else
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    void printLevelOrder(Node *root)
    {
        int h = height(root);

        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(root, i);
        }
    }

    Node *minValueNode(Node *root)
    {
        Node *curr = root;

        while (curr->left)
        {
            curr = curr->left;
        }

        return curr;
    }

    Node *deleteNode(Node *root, int value)
    {
        if (!root)
        {
            return root;
        }
        if (value < root->data)
        {
            root->left = deleteNode(root->left, value);
            return root;
        }
        else if (value > root->data)
        {
            root->right = deleteNode(root->right, value);
            return root;
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
            return root;
        }
    }

    /*Array to Balanced BST
        Extract the smallest lexicographical preorder traversal from array
        */

    void ArrayToBST(vector<int> &arr, int start, int end, vector<int> &ans)
    {
        if (start > end)
            return;
        int mid = start + (end - start) / 2; // mid = starting point + half the distance b/w start & end
        ans.push_back(arr[mid]);
        ArrayToBST(arr, start, mid - 1, ans); // for left child
        ArrayToBST(arr, mid + 1, end, ans);   // for right child
    }

    bool isBSTUtil(Node *root, Node *minNode, Node *maxNode)
    {
        if (!root)
        {
            return true;
        }
        if ((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data))
        {
            return false;
        }
        return isBSTUtil(root->left, minNode, root) && isBSTUtil(root->right, root, maxNode);
    }

    bool isBST(Node *root)
    {
        return isBSTUtil(root, NULL, NULL);
    }

    bool isFullBinaryTree(Node *root)
    {
        if (!root)
        {
            return true;
        }
        if (!root->left && !root->right)
        {
            return true;
        }
        if (root->left && root->right)
        {
            return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
        }
        return false;
    }

    Node *convertToFullBinaryTree(Node *root)
    {
        if (!root)
        {
            return NULL;
        }

        root->left = convertToFullBinaryTree(root->left);
        root->right = convertToFullBinaryTree(root->right);

        // If the node has only one child, prune it
        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        return root;
    }

    void storeInorder(Node *root, vector<int> &inorder)
    {
        if (!root)
        {
            return;
        }
        storeInorder(root->left, inorder);
        inorder.push_back(root->data);
        storeInorder(root->right, inorder);
    }

    Node *buildBalancedTree(vector<int> &inorder, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        Node *root = new Node(inorder[mid]);

        root->left = buildBalancedTree(inorder, start, mid - 1);
        root->right = buildBalancedTree(inorder, mid + 1, end);

        return root;
    }

    Node *balanceBST(Node *root)
    {
        vector<int> inorder;
        storeInorder(root, inorder);                              // Step 1: Extract elements in sorted order
        return buildBalancedTree(inorder, 0, inorder.size() - 1); // Step 2: Build balanced tree
    }
};

int main()
{
    BST tree;
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    // Insert elements into the BST
    for (int val : arr)
    {
        tree.root = tree.insert(tree.root, val);
    }

    // Check if the tree is a BST
    cout << "Is BST: " << (tree.isBST(tree.root) ? "Yes" : "No") << endl;

    // Check if the tree is a Full Binary Tree
    cout << "Is Full Binary Tree: " << (tree.isFullBinaryTree(tree.root) ? "Yes" : "No") << endl;

    // Convert BST to Full Binary Tree
    tree.root = tree.convertToFullBinaryTree(tree.root);
    cout << "Tree after converting to Full Binary Tree (Inorder Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    // Re-check if the tree is a Full Binary Tree
    cout << "Is Full Binary Tree after conversion: " << (tree.isFullBinaryTree(tree.root) ? "Yes" : "No") << endl;

    return 0;
}
