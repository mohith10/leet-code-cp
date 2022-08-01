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
 /*void removeDuplicates(Node* head){
     if(head == NULL) return;
     
     map<int,int> hashMap;
     Node* listIterator = head;
     Node* prevNodeIterator = NULL;
     while(listIterator!=NULL){
        if(hashMap[listIterator->data]!=0){
            prevNodeIterator->next = listIterator->next;
            listIterator = listIterator->next;
        }else{
            hashMap[listIterator->data] = 1;
            prevNodeIterator = listIterator;
            listIterator = listIterator->next;
        }
     }// Following approach uses O(n) space, so putting a code which runs in O(n2) but no space comlexity
 }*/
 
 void removeDuplicates(Node* head){
     if(head == NULL) return;
     
     Node* listIterator = head;
     Node* secondListIterator = NULL;
     while(listIterator!=NULL){
         secondListIterator = listIterator;
         while(secondListIterator->next!=NULL){
            if(secondListIterator->next->data == listIterator->data){
                secondListIterator->next = secondListIterator->next->next;
            }else{
                secondListIterator = secondListIterator->next;
            }
         }
         listIterator = listIterator->next;
     }
   
 }
 
 
 int main() {
 	Node* head = NULL;
 	int n;
 	cin>>n;
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
 	removeDuplicates(head);
 	printLinkedlist(head);
 	return 0;
 }
