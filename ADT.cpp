#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Operations provided by the ADT
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    T top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            // You might want to handle this case differently in a production setting
            throw std::out_of_range("Stack is empty");
        }
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};
/*
The Stack class is a template class that can hold elements of any type T.
The operations provided by the ADT include push, pop, front, isEmpty, and size.
*/
int main() {
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "front element: " << myStack.Top() << std::endl;
    std::cout << "Stack size: " << myStack.size() << std::endl;

    myStack.pop();

    std::cout << "front element after pop: " << myStack.Top() << std::endl;
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
/*
This example demonstrates how to use the Stack ADT to perform stack operations.
The client code interacts with the stack through the specified operations (push, pop, front, isEmpty, and size) without needing to know the internal implementation details of the stack.

In summary, encapsulation is achieved by hiding the implementation details (e.g., the elements vector, functions details: push, pop, front, isEmpty, and size) within the class,
and abstraction is achieved by providing a clear, high-level interface for users to interact with the stack.
Users don't need to know how the stack is implemented internally; they work with the abstracted interface,
relying on the provided operations to manipulate the stack.

Abstraction let users see that:
template <typename T>
class Stack {
public:
    void push(const T& value);
    void pop();
    T front() const;
    bool isEmpty() const;
    size_t size() const;
private:
    // Data members and potentially private helper functions...
};
They don't need to know about the internal use of a vector;
instead, they interact with the stack using operations like push, pop, front, isEmpty, and size.
The abstraction allows users to focus on the behavior of the stack and the operations they want to perform,
without dealing with the low-level implementation details.

encapsulation hides the implementation details

 */
