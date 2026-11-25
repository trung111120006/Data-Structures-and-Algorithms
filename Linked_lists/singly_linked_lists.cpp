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


int main (){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* thrid = new Node(30);
    first->next = second; 
    second->next = thrid;
}