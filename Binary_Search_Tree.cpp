#include <iostream>
#include <cassert>

using namespace std;

struct nodeType {
    int info;
    nodeType *left;
    nodeType *right;
};


class binarySearchTreeType {
public:
    bool isEmpty();

    bool search(int);

    bool searchRec(int);

    void insert(int);

    void remove(int);

    void inorderTraversal();

    void preorderTraversal();

    void postorderTraversal();

    int treeHeight();

    int treeNodeCount();

    int treeLeavesCount();

    void clearTree();

    binarySearchTreeType();

    ~binarySearchTreeType();

private:
    nodeType *root;

    void clear(nodeType *&p);

    void inorder(nodeType *p);

    void preorder(nodeType *p);

    void postorder(nodeType *p);

    int height(nodeType *p);

    int max(int x, int y);

    int nodeCount(nodeType *p);

    int leavesCount(nodeType *p);

    void deleteFromTree(nodeType *&p);

    bool searchRecPriv(nodeType *, int);
};


binarySearchTreeType::binarySearchTreeType() {
    root = nullptr;
}


bool binarySearchTreeType::isEmpty() {
    return (root == nullptr);
}


void binarySearchTreeType::inorderTraversal() {
    inorder(root);
}


void binarySearchTreeType::preorderTraversal() {
    preorder(root);
}


void binarySearchTreeType::postorderTraversal() {
    postorder(root);
}


int binarySearchTreeType::treeHeight() {
    return height(root);
}


int binarySearchTreeType::treeNodeCount() {
    return nodeCount(root);
}


int binarySearchTreeType::treeLeavesCount() {
    return leavesCount(root);
}


void binarySearchTreeType::inorder(nodeType *p) {
    if (p != nullptr) {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}


void binarySearchTreeType::preorder(nodeType *p) {
    if (p != nullptr) {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}


void binarySearchTreeType::postorder(nodeType *p) {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
    }
}


void binarySearchTreeType::clear(nodeType *&p) {
    if (p != nullptr) {
        clear(p->left);
        clear(p->right);
        delete p;
        p = nullptr;
    }
}


void binarySearchTreeType::clearTree() {
    clear(root);
}

binarySearchTreeType::~binarySearchTreeType() {
    clear(root);
}


int binarySearchTreeType::height(nodeType *p) {
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}


int binarySearchTreeType::max(int x, int y) {
    if (x >= y)
        return x;
    else
        return y;
}


int binarySearchTreeType::nodeCount(nodeType *p) {
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->left) + nodeCount(p->right);
}


int binarySearchTreeType::leavesCount(nodeType *p) {
    if (p == nullptr)
        return 0;
    else if ((p->left == nullptr) && (p->right == nullptr))
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}

bool binarySearchTreeType::search(int item) {
    nodeType *current = root;

    while (current != nullptr) {
        if (current->info == item)
            return true;
        else if (current->info > item)
            current = current->left;
        else
            current = current->right;
    }

    return false;
}

bool binarySearchTreeType::searchRec(int item) {
    return searchRecPriv(root, item);
}

bool binarySearchTreeType::searchRecPriv(nodeType *p, int item) {
    if (p == nullptr)
        return false;
    else if (p->info == item)
        return true;
    else if (p->info > item)
        return searchRecPriv(p->left, item);
    else
        return searchRecPriv(p->right, item);
}

void binarySearchTreeType::insert(int item) {
    nodeType *current;  //pointer to traverse the tree
    nodeType *trailCurrent; //pointer behind current
    nodeType *newNode;  //pointer to create the node

    newNode = new nodeType;
    assert(newNode != nullptr);
    newNode->info = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr)
        root = newNode;
    else {
        current = root;

        while (current != nullptr) {
            trailCurrent = current;

            if (current->info == item) {
                cout << "The insert item is already in the list -- ";
                cout << "duplicates are not allowed." << endl;
                return;
            } else if (current->info > item)
                current = current->left;
            else
                current = current->right;
        }//end while

        if (trailCurrent->info > item)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}

//this function only determines the node to be deleted
void binarySearchTreeType::remove(int item) {
    nodeType *current;  //pointer to traverse the tree
    nodeType *trailCurrent; //pointer behind current

    if (root == nullptr) {
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }
    if (root->info == item) {
        deleteFromTree(root);
        return;
    }

    //if you get here, then the item to be deleted is not the root
    trailCurrent = root;

    if (root->info > item)
        current = root->left;
    else
        current = root->right;

    //search for the item to be deleted.
    while (current != nullptr) {
        if (current->info == item)
            break;
        else {
            trailCurrent = current;
            if (current->info > item)
                current = current->left;
            else
                current = current->right;
        }
    }// once the while is done, current points to either nullptr or to the node to be deleted

    if (current == nullptr)
        cout << "The delete item is not in the tree." << endl;
    else if (trailCurrent->info > item)
        deleteFromTree(trailCurrent->left);
    else
        deleteFromTree(trailCurrent->right);
}

void binarySearchTreeType::deleteFromTree(nodeType *&p) {
    nodeType *current;    //pointer to traverse
    //the tree
    nodeType *trailCurrent;   //pointer behind current
    nodeType *temp;        //pointer to delete the node

    if (p->left == nullptr && p->right == nullptr) {
        delete p;
        p = nullptr;
    } else if (p->left == nullptr) {
        temp = p;
        p = p->right;
        delete temp;
    } else if (p->right == nullptr) {
        temp = p;
        p = p->left;
        delete temp;
    } else {
        current = p->left;
        trailCurrent = nullptr;

        while (current->right != nullptr) {
            trailCurrent = current;
            current = current->right;
        }//end while

        p->info = current->info;

        if (trailCurrent == nullptr) //current did not move;
            //current == p->left; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;

        delete current;
    }//end else
}//end deleteFromTree

int main() {
    binarySearchTreeType b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.insert(6);
    b.insert(4);
    b.insert(3);
    b.remove(4);
    //b.inorderTraversal();
    //b.postorderTraversal();
    b.preorderTraversal();
    return 0;
}