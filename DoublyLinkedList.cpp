
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

  
    void push_back(T value) {
        Node<T>* newNode = new Node<T>();

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void forward() {
        Node<T>* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << "\n";
    }

   
    void reversed() {
        Node<T>* current = tail;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }

        std::cout << "\n";
    }


    ~DoublyLinkedList() {
        Node<T>* current = head;

        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Prevent copying a list into a new object
    DoublyLinkedList(const DoublyLinkedList&) = delete;

    // Prevent assigning one list to another
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
};

int main() {
    int n;

    std::cout << "How many elements? ";
    std::cin >> n;

    DoublyLinkedList<int> list;


    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        list.push_back(val);
    }

    std::cout << "Usual list as we cin the values: ";
    list.forward();

    std::cout << "Reversed type of our list: ";
    list.reversed();

    return 0;
}
