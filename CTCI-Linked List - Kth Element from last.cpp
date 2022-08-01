#include <bits/stdc++.h>
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
        return newNode;
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
     cout<<endl;
 }
 /*Question Code*/
 Node* findKthElementFromLast(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    Node* listIterator = head;
    Node* kDistanceApartIterator = head;
    for(int steps = 1;steps<k && kDistanceApartIterator!=NULL; steps++){
        kDistanceApartIterator = kDistanceApartIterator->next;
    }
    if(kDistanceApartIterator == NULL) return NULL;
    
    while(kDistanceApartIterator->next!=NULL){
        listIterator = listIterator->next;
        kDistanceApartIterator = kDistanceApartIterator->next;
    }
    
    return listIterator;
 }
 
 int main() {
 	Node* head = NULL;
 	int n,k;
 	cin>>n>>k;
 	for(int node = 0; node<n; node++){
 	    int nodeValue;
 	    cin>>nodeValue;
 	    if(node == 0){
 	        head = insert(head, nodeValue);
 	    }else{
 	        insert(head,nodeValue);
 	    }
 	}
 	printLinkedlist(head);
 	Node* poistionKthElementFromLast = findKthElementFromLast(head,k);
 	if(poistionKthElementFromLast!=NULL) cout<<poistionKthElementFromLast->data;
 	return 0;
 }
