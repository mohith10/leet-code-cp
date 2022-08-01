#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(Node* head, int value){
    if(head == NULL){
       Node* newNode = new Node();
       newNode->data = value;
       newNode->next = NULL;
       head = newNode;
       return head;
    }
    Node* listIterator = head;
    while(listIterator->next!=NULL){
        listIterator = listIterator->next;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    listIterator->next = newNode;
    return head;
}

void printLinkedlist(Node* head){
    Node* listIterator = head;
    while(listIterator!=NULL){
        cout<<listIterator->data<<" ";
        listIterator = listIterator->next;
    }
}
int main() {
	Node* head = NULL;
	head = insert(head, 3);
	insert(head,4);
	insert(head,5);
	printLinkedlist(head);
	return 0;
}
