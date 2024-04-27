#include <iostream>

using namespace std;

// doubly linked list
struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) { // Empty list
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }
};

// Helper function to swap values of two nodes
void swap(Node* a, Node* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Function to partition the list
Node* partition(Node* low, Node* high) {
    int pivot = high->value;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->value <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}

// The main function to implement QuickSort
void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

// Main function to test the implementation
int main() {
    DoublyLinkedList bosaty;
    bosaty.append(4);
    bosaty.append(2);
    bosaty.append(5);
    bosaty.append(3);
    bosaty.append(1);

    cout << "Original list: ";
    bosaty.display();

    quickSort(bosaty.getHead(), bosaty.getTail());

    cout << "Sorted list: ";
    bosaty.display();

    return 0;
}