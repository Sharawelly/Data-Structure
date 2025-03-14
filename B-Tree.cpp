#include <iostream>
using namespace std;

// Template for B-Tree Node
template<class T, int Order>
struct Node {
    int keyCount;       // Number of keys in the node
    int maxKeys;        // Maximum number of keys allowed
    T* keys;            // Array of keys
    Node** children;    // Array of child pointers

    Node(int order);
    int insertKey(T value);
    Node* splitNode(T* middleKey);
    void printDFS(int level) const;
    ~Node();
};

// Constructor for Node
template<class T, int Order>
Node<T, Order>::Node(int order) : maxKeys(order), keyCount(0) {
    keys = new T[order];
    children = new Node*[order + 1](); // Initialize with null pointers
}

// Insert a key into the node
template<class T, int Order>
int Node<T, Order>::insertKey(T value) {
    if (!children[0]) { // If this is a leaf node
        // Insert the key and sort the keys
        int index = 0;
        while (index < keyCount && value > keys[index])
            index++;
        for (int i = keyCount; i > index; i--) {
            keys[i] = keys[i - 1];
        }
        keyCount++;
        keys[index] = value;

    } else {
        // Find the child to insert the value
        int childIndex = 0;
        while (childIndex < keyCount && value > keys[childIndex])
            childIndex++;

        // Insert into the child
        int splitRequired = children[childIndex]->insertKey(value);

        if (splitRequired) {
            // Handle splitting of the child node
            T middleKey;
            Node<T, Order>* newChild = children[childIndex]->splitNode(&middleKey);

            // Insert middleKey into the current node
            for (int i = keyCount; i > childIndex; i--) {
                keys[i] = keys[i - 1];
                children[i + 1] = children[i];
            }

            keys[childIndex] = middleKey;
            children[childIndex + 1] = newChild;
            keyCount++;
        }
    }

    return keyCount == maxKeys; // Return true if this node needs to be split
}

// Split a node and return the new right sibling
template<class T, int Order>
Node<T, Order>* Node<T, Order>::splitNode(T* middleKey) {
    int midIndex = keyCount / 2;
    *middleKey = keys[midIndex];

    Node<T, Order>* newNode = new Node<T, Order>(maxKeys); // A new node (newNode) is created to hold the right half of the keys and children.
    newNode->keyCount = keyCount - midIndex - 1;

    for (int i = 0; i < newNode->keyCount; i++) {
        newNode->keys[i] = keys[midIndex + 1 + i]; // Keys from the right half (starting from midIndex + 1) are moved to the newNode.
        newNode->children[i] = children[midIndex + 1 + i]; // Corresponding child pointers are also moved to the newNode.
    }

    newNode->children[newNode->keyCount] = children[keyCount];

    keyCount = midIndex; // Reduce the key count of the current node (The current node (this) is updated to hold only the left half of the keys and children. The keyCount is reduced to midIndex.

    return newNode; // The newNode containing the right half of the keys and children is returned to the caller, typically the parent node.
}

// Print the tree in DFS order
template<class T, int Order>
void Node<T, Order>::printDFS(int level) const {
    for (int i = 0; i < level; i++)
        cout << "  ";

    for (int i = 0; i < keyCount; i++) {
        if (i > 0) cout << ",";
        cout << keys[i];
    }
    cout << '\n';

    for (int i = 0; i <= keyCount; i++) {
        if (children[i])
            children[i]->printDFS(level + 1);
    }
}

// Destructor for Node
template<class T, int Order>
Node<T, Order>::~Node() {
    delete[] keys;
    for (int i = 0; i <= keyCount; i++)
        delete children[i];
}

// Template for B-Tree
template<class T, int Order>
class BTree {
private:
    Node<T, Order>* root;

public:
    BTree();
    void insert(T value);
    void printTree() const;
    ~BTree();
};

// Constructor for B-Tree
template<class T, int Order>
BTree<T, Order>::BTree() : root(nullptr) {}

// Insert a value into the B-Tree
template<class T, int Order>
void BTree<T, Order>::insert(T value) {
    if (!root) {
        root = new Node<T, Order>(Order);
        root->keys[0] = value;
        root->keyCount = 1;
    } else {
        int splitRequired = root->insertKey(value);

        if (splitRequired) {
            T middleKey;
            Node<T, Order>* newRoot = new Node<T, Order>(Order);
            Node<T, Order>* newChild = root->splitNode(&middleKey);

            newRoot->keys[0] = middleKey;
            newRoot->keyCount = 1;
            newRoot->children[0] = root;
            newRoot->children[1] = newChild;


            root = newRoot;
        }
    }
}

// Print the B-Tree
template<class T, int Order>
void BTree<T, Order>::printTree() const {
    if (root)
        root->printDFS(0);
    else
        cout << "The B-Tree is empty" << endl;
}

// Destructor for B-Tree
template<class T, int Order>
BTree<T, Order>::~BTree() {
    delete root;
}

int main() {
    BTree<int, 3> intTree;
    intTree.insert(1);
    intTree.insert(5);
    intTree.insert(0);
    intTree.insert(4);
    intTree.insert(3);
    intTree.insert(2);
//    intTree.insert(2);
    intTree.printTree();

    BTree<char, 5> charTree;
    charTree.insert('G');
    charTree.insert('I');
    charTree.insert('B');
    charTree.insert('J');
    charTree.insert('C');
    charTree.insert('A');
    charTree.insert('K');
    charTree.insert('E');
    charTree.insert('D');
    charTree.insert('S');
    charTree.insert('T');
    charTree.insert('R');
    charTree.insert('L');
    charTree.insert('F');
    charTree.insert('H');
    charTree.insert('M');
    charTree.insert('N');
    charTree.insert('P');
    charTree.insert('Q');
    charTree.printTree();

    return 0;
}
