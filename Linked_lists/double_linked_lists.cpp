/*
Basic operations for a Doubly Linked List:
- Traversal Forward
- Traversal Backward
- Insert at Beginning
- Insert at End
- Insert at Position
- Delete Node
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert at a specific position (1-based index)
    void insertPosition(int value, int pos) {
        if (pos <= 1 || head == nullptr) {
            insertBeginning(value);
            return;
        }

        Node* current = head;
        // Move to the node right before the target position (pos - 1)
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }

        // If position is at the end or out of bounds, insert at the end
        if (current == nullptr || current->next == nullptr) {
            insertEnd(value);
            return;
        }

        // Link newNode between current and current->next
        Node* newNode = new Node(value);
        newNode->next = current->next;
        newNode->prev = current;

        current->next->prev = newNode;
        current->next = newNode;
    }

    // Traverse forward
    void displayForward() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Traverse backward
    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    // Search
    bool search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value)
                return true;

            current = current->next;
        }

        return false;
    }

    // Delete by value
    void deleteNode(int value) {
        Node* current = head;

        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) return;

        if (current->prev != nullptr)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != nullptr)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
    }

    // Count nodes
    int getLength() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    // Free memory automatically when the object goes out of scope
    ~DoublyLinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBeginning(5);       // List: 5 10 20 30
    list.insertPosition(15, 3);    // List: 5 10 15 20 30

    cout << "Forward:  ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    cout << "Search 20: " << list.search(20) << endl;

    list.deleteNode(20);
    
    cout << "After deleting 20: ";
    list.displayForward();

    cout << "Length: " << list.getLength() << endl;

    return 0;
}