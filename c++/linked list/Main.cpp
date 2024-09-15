#include <iostream>
#include <string>
template <typename T>
struct Node {
public:
    T data;
    std::shared_ptr<Node> next;
        Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int listSize;

public:
    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

        void push_front(T value) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        listSize++;
    }

    void push_back(T value) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void pop_front() {
        if (head == nullptr) {
            std::cout << "List is empty, cannot pop front\n";
            return;
        }
        head = head->next;
        listSize--;
    }

    void pop_back() {
        if (head == nullptr) {
            std::cout << "List is empty, cannot pop back\n";
            return;
        }
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            std::shared_ptr<Node<T>> current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            tail = current;
        }
        listSize--;
    }

    std::shared_ptr<Node<T>> find(T value) {
        std::shared_ptr<Node<T>> current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(T value) {
        std::shared_ptr<Node<T>> current = head;
        std::shared_ptr<Node<T>> prev = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                if (current == head) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                listSize--;
                return;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "Element not found, cannot remove\n";
    }

    void print() {
        std::shared_ptr<Node<T>> current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool is_empty() {
        return listSize == 0;
    }

    int size() {
        return listSize;
    }
};

int main() {
    LinkedList<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    myList.print(); // Output: 1 2 3

    myList.pop_back();

    myList.print(); // Output: 1 2

    myList.push_front(0);

    myList.print(); // Output: 0 1 2

    std::shared_ptr<Node<int>> node = myList.find(1);
    if (node != nullptr) {
        std::cout << "Found node with value 1\n";
    }
    else {
        std::cout << "Node with value 1 not found\n";
    }

    myList.remove(1);

    myList.print(); // Output: 0 2

    std::cout << "List size: " << myList.size() << std::endl; // Output: 2

    std::cout << "Is list empty? " << (myList.is_empty() ? "Yes" : "No") << std::endl; // Output: No

    return 0;
}