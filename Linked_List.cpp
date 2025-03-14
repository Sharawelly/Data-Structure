#include <iostream>

using namespace std;
struct nodeType {
    int info; // Data or information stored in the node
    nodeType *next; // Pointer to the next node in the linked list
    // The reason the next pointer in a linked list node is not of type int is because it needs to point to another node, not to an integer value.
};

/*
In a linked list, each node contains two main components:

Data: This is typically represented by an int or any other data type, depending on the application requirements.
It holds the actual information associated with the node.

Pointer to the next node: This pointer points to the next node in the linked list.
It allows us to traverse the list sequentially by following the chain of nodes.

If next were to be of type int, it would only be capable of holding an integer value, but in a linked list,
it needs to hold a memory address, specifically the memory address of the next node in the sequence.
Hence, it's declared as a pointer to the same type of structure as the current node, allowing it to point to another node in the linked list.
This pointer enables the linkage between nodes, forming the linked list data structure.
*/

class linkedListType {
public:
    linkedListType();

    int listSize() const;

    bool isEmpty() const;

    int seqSearch(int);

    void remove(int);

    void insertFirst(int);

    void insertEnd(int);

    void insertAt(int, int);

    void removeAt(int);

    void print();

    void clearList();

    void insertOrdered(int);

    void removeFirst();

    void removeLast();

    void removeLast2();

    int removeOddSumEven();

    void reverse();

    ~linkedListType();

private:
    nodeType *first, *last;
    int length;
};

int linkedListType::removeOddSumEven() {
    int sum = first->info;
    nodeType *current = first->next;
    nodeType *trailCurrent = first;

    while (current != nullptr) {
        if (current->info % 2 == 0) {
            sum += current->info;
            trailCurrent = current;
            current = current->next;
        } else {
            trailCurrent->next = current->next;
            delete current;
            length--;
            current = trailCurrent->next;
        }
    }
    return sum;
}

void linkedListType::removeLast() {
    if (length == 0)
        cout << "ERROR: EMPTY LIST" << endl;
    else if (length == 1) {
        delete first;
        last = first = nullptr;
        length--;
    } else {
        nodeType *current = first->next;
        nodeType *trailCurrent = first;
        while (current != last) {
            trailCurrent = current;
            current = current->next;
        }
        delete current;
        trailCurrent->next = nullptr;
        last = trailCurrent;
        length--;
    }
}

void linkedListType::removeLast2() {
    if (length == 0)
        cout << "ERROR: EMPTY LIST" << endl;
    else if (length == 1) {
        delete first;
        last = first = nullptr;
        length--;
    } else {
        nodeType *current = first;
        while (current->next != last)
            current = current->next;

        delete last;
        current->next = nullptr;
        last = current;
        length--;
    }
}

void linkedListType::removeFirst() {
    if (length == 0)
        cout << "ERROR: EMPTY LIST" << endl;
    else if (length == 1) {
        delete first;
        last = first = nullptr;
        length--;
    } else {
        nodeType *current = first;
        first = first->next;
        delete current;// to avoid memory leak
        length--;
    }
}

linkedListType::linkedListType() {
    first = last = nullptr;
    length = 0;
}

int linkedListType::listSize() const {
    return length;
}

bool linkedListType::isEmpty() const {
    return (length == 0);
}

int linkedListType::seqSearch(int item) {
    nodeType *current = first;
    int loc = 0;
    while (current != nullptr) {
        if (current->info == item)
            return loc;
        current = current->next;
        loc++;
    }
    return -1;
}

void linkedListType::remove(int item) {
    if (isEmpty()) {
        cout << "Can not remove from empty list\n";
        return;
    }

    nodeType *current, *trailCurrent;
    if (first->info == item)//delete the first element, special case
    {
        current = first;

        first = first->next;
        delete current;
        length--;
        if (length == 0)
            last = nullptr;
    } else {
        current = first->next;
        trailCurrent = first;
        while (current != nullptr) {
            if (current->info == item)
                break;
            trailCurrent = current;
            current = current->next;
        }

        if (current == nullptr)
            cout << "The item is not there\n";
        else {
            trailCurrent->next = current->next;
            if (last == current) //delete the last item
                last = trailCurrent;
            delete current;
            length--;
        }
    }
}


void linkedListType::insertFirst(int item) {
    nodeType *newNode = new nodeType;
    newNode->info = item;
    if (length == 0) {
        first = last = newNode;
        newNode->next = nullptr;
    } else {
        newNode->next = first;
        first = newNode;// To make first points to the new element that has just been added at the beginning of the linked list.
    }
    length++;
}

void linkedListType::insertEnd(int item) {
    nodeType *newNode = new nodeType;
    newNode->info = item;
    if (length == 0) {
        first = last = newNode;
        newNode->next = nullptr;
    } else {
        last->next = newNode;
        newNode->next = nullptr;
        last = newNode;
    }
    length++;
}


void linkedListType::insertAt(int loc, int item) {
    if (loc < 0 || loc > length)
        cout << "ERROR: Out of range" << endl;
    else {
        if (loc == 0) //insert at the begining
            insertFirst(item);
        else if (loc == length) //insert at the end;
            insertEnd(item);
        else {
            nodeType *newNode = new nodeType;
            newNode->info = item;
            nodeType *current = first;
            for (int i = 1; i < loc; i++)
                current = current->next;

            newNode->next = current->next;
            current->next = newNode;
            length++;
        }

    }
}

void linkedListType::removeAt(int loc) {
    if (loc < 0 || loc >= length)
        cout << "ERROR: Out of range" << endl;
    else {
        nodeType *current, *trailCurrent;
        if (loc == 0) {
            current = first;
            first = first->next;
            delete current;
            length--;
            if (length == 0)
                last = nullptr;
        } else {
            current = first->next;
            trailCurrent = first;
            for (int i = 1; i < loc; i++) {
                trailCurrent = current;
                current = current->next;
            }

            trailCurrent->next = current->next;
            if (last == current) //delete the last item
                last = trailCurrent;
            delete current;
            length--;
        }
    }
}


void linkedListType::print() {
    nodeType *current = first;
    while (current != nullptr) {
        cout << current->info << endl;
        current = current->next;
    }
}

void linkedListType::clearList() {
    nodeType *current;
    while (first != nullptr) {
        current = first;
        first = first->next;
        delete current;
    }
    last = nullptr;
    length = 0;
}

void linkedListType::insertOrdered(int item) {
    nodeType *newNode = new nodeType;
    newNode->info = item;

    if (first == nullptr) {
        first = last = newNode;
        newNode->next = nullptr;
        length++;
    } else if (first->info >= item) {
        newNode->next = first;
        first = newNode;
        length++;
    } else {
        nodeType *current = first->next;
        nodeType *trailCurrent = first;

        while (current != nullptr) {
            if (current->info >= item)
                break;
            current = current->next;
            trailCurrent = trailCurrent->next;
        }
        if (current == nullptr) {
            last->next = newNode;
            newNode->next = nullptr;
            last = newNode;
            length++;
        } else {
            trailCurrent->next = newNode;
            newNode->next = current;
            length++;
        }
    }
}

void linkedListType::reverse() {
    nodeType *prev, *next, *curr;
    prev = nullptr;
    curr = first;
    next = curr->next;
    while (next != nullptr)//curr!=nullptr
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
}

linkedListType::~linkedListType() {
    clearList();
}

int main() {
    linkedListType l1;
    l1.insertAt(0, 10);
    l1.insertAt(1, 15);
    l1.insertAt(2, 20);
    l1.insertAt(3, 25);
    l1.insertFirst(5);
    l1.insertEnd(30);
    cout << l1.seqSearch(15) << '\n';
    l1.print();

    return 0;
}