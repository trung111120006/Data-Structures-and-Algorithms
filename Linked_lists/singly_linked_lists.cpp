/*
The first time, we need to get acquainted the 5 element: 
- Traversal
- Insert at Beginning
- Insert at End
- Delete node
- Search
*/
#include <bits/stdc++.h>
using namespace std; 

struct Node {
    int data;
    Node* next;

    Node(int value){
        data = value; 
        next = nullptr;
    }
};
// traversal
void traversal(Node* head){
    Node* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current -> next;
    }
}
//Insert at beginning 
void insert_beginning(Node* &head, int value){
    Node* newnode = new Node(value);
    newnode -> next = head;
    head = newnode;
}
//Insert at end 
void insert_end(Node* &head, int value){
    Node* newnode = new Node(value);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    Node* current = head; 
    while (current -> next != nullptr){
        current = current -> next;
    }
    current -> next = newnode;
}
//Delete node
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != nullptr &&
           current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
//Search 
bool search(Node* head, int target) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }

        current = current->next;
    }

    return false;
}

int main (){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    first->next = second; 
    second->next = third;
    traversal(first);
    Node* zero = new Node(0);
    insert_beginning(zero , 0);
}